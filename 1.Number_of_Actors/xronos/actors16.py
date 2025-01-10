import xronos
import time
import numpy as np
from datetime import timedelta

num_actors = 16
num_rounds = 10

env = xronos.Environment()

class clientReactor(xronos.Reactor):
    global_parameters = xronos.InputPortDeclaration()
    updated_parameters = xronos.OutputPortDeclaration()

    @xronos.reaction
    def on_startup(self, interface):
        interface.add_trigger(self.startup)
        def handler():
            pass
        return handler
    @xronos.reaction
    def on_global_parameters(self, interface):
        global_parameters = interface.add_trigger(self.global_parameters)
        updated_parameters = interface.add_effect(self.updated_parameters)
        def handler():
            time.sleep(0.5)
            new_parameter = (global_parameters.get()).copy()
            updated_parameters.set(new_parameter)
        return handler

class serverReactor(xronos.Reactor):
    round_num = None
    benchmark_start_time = None
    total_start_time = None
    global_parameters = xronos.OutputPortDeclaration() 
    updated_parameters = []
    def __init__(self):
        super().__init__()
        for i in range(num_actors):
            self.updated_parameters.append(xronos.InputPort(f"port{i}", self))
    @xronos.reaction
    def on_startup(self, interface):
        interface.add_trigger(self.startup)
        global_parameters = interface.add_effect(self.global_parameters)
        def handler():
            self.round_num = 0
            self.results = [0] * num_actors
            self.benchmark_start_time = None
            self.total_start_time = None
            val = np.ones(1310720)
            global_parameters.set(val)
        return handler
        
    @xronos.reaction
    def on_updated_parameters(self, interface):
        global_parameters = interface.add_effect(self.global_parameters)
        updated_parameters = []
        for i in range(num_actors):
            u = interface.add_trigger(self.updated_parameters[i])
            updated_parameters.append(u)
        def handler():
            # Retrieve value from each client
            for i in range(num_actors):
                self.results[i] = updated_parameters[i].get()

            # Check and set the benchmark start time for the first round
            if self.round_num == 0:
                self.benchmark_start_time = time.time()
                self.total_start_time = time.time()

            if self.round_num == num_rounds:
                env.request_shutdown()

            # Calculate the overhead time difference for the current round and reset the start time for the next round
            current_time = time.time()
            overhead_time = current_time - self.benchmark_start_time - 0.5
            training_time = current_time - self.total_start_time
            self.benchmark_start_time = current_time

            # Print the overhead time and round number
            print(f"Round: {self.round_num}")
            print(f"Total training time: {training_time:.4f} seconds")
            print(f"Overhead: {overhead_time:.4f} seconds \n")

            self.round_num += 1

            # Update the global parameters with the results from the first client for the next round
            global_parameters.set(self.results[0].copy())
        return handler

client = []
server = env.create_reactor("server", serverReactor)
for i in range(num_actors):
    client.append(env.create_reactor(f"client{i}", clientReactor))
    env.connect(server.global_parameters, client[i].global_parameters, delay=timedelta(0))
    print("client updated_parameters", client[i].updated_parameters)
    print("server updated_parameters", server.updated_parameters)
    env.connect(client[i].updated_parameters, server.updated_parameters[i])

env.execute()
