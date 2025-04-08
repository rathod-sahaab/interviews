# Mediator Pattern

Loose coupling by avoiding objects referring to each other, eliminate direct communication.

> The Mediator pattern suggests that you should cease all direct communication between the components which you want to make independent of each other. Instead, these components must collaborate indirectly, by calling a special mediator object that redirects the calls to appropriate components. As a result, the components depend only on a single mediator class instead of being coupled to dozens of their colleagues

## Contrast

### Observer pattern

In observer pattern the intent is event listening and execution on event.

Mediator pattern: Intent is to have all communication through the master object/co-ordinator.
