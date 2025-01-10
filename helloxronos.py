import xronos


class Hello(xronos.Reactor):
    @xronos.reaction
    def hello(self, interface):
        interface.add_trigger(self.startup)
        return lambda: print("Hello, World!")


def main():
    env = xronos.Environment()
    env.create_reactor("hello", Hello)
    env.execute()


if __name__ == "__main__":
    main()