# Blocking I/O for C++ event transmission between classes

The idea in realtime processing in userspace is using blocking
I/O which unblocks after an event has happened. Then another
class can be called with a callback.

There are two demos: one using `std::function` as a callback and
the other using a callback interface with an abstract/virtual method.

## How to compile?

```
cmake .
make
```

## How to run?
 
 1. Bare program just showing that `getchar()` is blocking. This is
 used here as a trivial unblocking I/O operation.
 2. `std::function` callback: `./demoStdFunc` and then press <ENTER> to
 trigger an event.
 3. Callback interface callback: `./demoInterface` and press <ENTER> to
 trigger an event.

# Credit

Bernd Porr
