# cpp-store

> A prototype for sharing state in a C++ application through a variables store


<br>

## Disclaimer

This is an experiment with C++, usage should be **for testing purposes only**.

Relying on a global state in an application is generally considered bad practice. This project is an attempt at creating a *store* to hold data that can be shared among classes while minimizing the traditional drawbacks of a global state.

## Features

* Predictability is improved as `Get` and `Set` visibly pinpoint the classes that depend on a particular variable; they can easily be mocked to set up unit tests involving only the required number of variables and control on the access.
* If the implementation was perfect, the variables could theoretically not be modified by any other mean than inheritance from `Get` or `Set`. The present code enforces correct usage but can probably be bypassed.
* A `namespace` is used instead of the more debatable *Singleton* or *Monostate* patterns. As such, storage is explicitly `static` instead of hiding this particularity inside a normal-looking class.

## Test the Qt Demo
* Qt5.7 is required as the demo uses the new signal / slot syntax
* Build using CMake and run

## Use in Your Application
* Standalone headers are in `include/`
	* `variable.h` defines the `Variable<T>` template class
	* `binding.h` defines the `Get<T>`, `Set<T>` and `GetSet<T>` classes
* Create a `namespace` with external variables defined in exactly one compilation unit
* Get a variable's value by inheriting `Get<T>::From<Variable<T>>` and calling `get` or `subscribe`
* Set a variable's value by inheriting `Set<T>::Into<Variable<T>>` and calling `set`
