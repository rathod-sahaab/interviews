# Design pattern implementations in C++

## Coverage

- [] Creational
  - [x] Singleton
  - [x] Prototype
  - [x] Builder
  - [x] Factory
  - [] Abstract Factory
- [] Structural
  - [x] Composite
  - [x] Decorator
  - [x] Proxy
  - [] Bridge
  - [] Flyweight
  - [] Facade
  - [] Adapter
- [] Behavioural
  - [x] Chain of responsibility
  - [x] Memento
  - [x] Visitor
  - [] Command
  - [] Iterator
  - [] Mediator
  - [] Observer
  - [] State
  - [] Strategy
  - [] Template Method

# Patterns overview

## Creational Patterns

These assist in creating objects

### Singleton

Helps in creating single object instance for whole application to share and re-use.

Usage

```cpp
const Config *config = Config::getInstance();
```
