#Expressions Genetic Algorithm
Genetic algorithm to generate expressions to solve a given problem

Overview
---
This program will use a genetic algorithm to generate an expression that equals the user's input.

For example, the user may specify `42` as their target value. A pool of random expressions will be generated `(eg 4*3-1+5, 3/2+6, etc)`. Internally, these expressions will be assigned a "fitness" rating that represents how close they are to the target. The more fit the expression, the more likely it will "breed" with the other equations to pass elements of itself on to future generation equations. `(ie: 4*3-1+5, 3/2+6 >>> 4*3+6)` Every time two expressions combine with each other, there is a chance their offspring will "mutate" and have something about it that neither of its parents have. `(ie: 4*3-1+5, 3/2+6 >>> 9*3+6)`

This is my implementation of a challenge question at the end of this genetic algorithm explanation: [Tutorial link](http://www.ai-junkie.com/ga/intro/gat1.html).

_Note that the expressions are evaluated from left to right and do not respect operator precedence._

About the Repository
---
This repository is a Visual Studio 2013 solution.
