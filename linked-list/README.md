# Linked List

A naive linked-list implementation for DSA class (does not follow class approach 1:1). I have commented parts I remembered to comment but the code should be straight-forward.

![Expected output ~ similar at least](./sc.png)

## Running
You need the [Zig](https://ziglang.org) (version 0.11.0) toolchain instead, it is my preferred build tool for this and other C++ projects. You can use [ZVM](https://zvm.app) to manage Zig versions, 0.12.0 completely breaks the build file and I do not have the time to figure out whatever they've changed or removed, I have tried but I would just stick with 0.11.0 here.

```sh
zig build && ./zig-out/bin/ll
```
