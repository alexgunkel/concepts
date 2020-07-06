Making It Explicit With C++-Concepts
====================================

# Most obvious: Error-Detection
The most obvious and often stated reason to use concepts is in finding the cause of compilation errors.

# When more is said than guaranteed
There are several situations when there might be more said in the concept than
the requirements are able to guarantee. In these cases the compiler won't help us,
but still the expressive power of our concepts can be very useful.

## Semantic Requirements
E.g., we might define the concept of a semi-group <H, +, 0> by sating the following requirements:
````
template<typename T, typename F>
concept semi_group = requires ()

````

## Implementation Details
There might be some Concepts that differ in their implementation details without having
differences in their behaviour 
