# C-Neural-Network-Engine

A lightweight, modular, zero-dependency neural network engine written purely in C11. Built from first principles, this project implements low-level tensor operations, automatic parameter initialization, multi-layer forward/backward execution passes, and first-order optimization routines without relying on high-level matrix libraries.

---

## Engine Architecture

The codebase is structured around a modular Unix-style core, separating base mathematical routines, neural network layer mechanics, non-linear activation transformations, loss metric computations, and gradient-based optimization algorithms.

```text
nn_engine/
├── include/
│   └── matrix.h           # Central API header & data structures
├── src/
│   ├── math_ops.c         # Flat 1D array linear algebra & dynamic matrix creation
│   ├── dense.c            # Fully-connected layer forward/backward passes & weight init
│   ├── activations.c      # Stable activation functions (ReLU, Sigmoid, Max-Subtracted Softmax)
│   ├── loss.c             # Objective loss functions & gradient calculations (MSE, Cross-Entropy)
│   └── sgd.c              # Stochastic Gradient Descent parameter update mechanics
├── main.c                 # Driver program & end-to-end integration test pass
└── README.md