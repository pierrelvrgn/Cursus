# Protocol

## Table of content

- Description
- Connect N
- The referee
- The protocol
- Players
- Messages

## Description

The document describes the protocol used by the `referee` program to arbitrate a game of connect N

## Connect N

Each players plays each after the other, the first player is selected by the `referee`.

On a turn one can only decide on a single column into which to drop one his pieces,
the piece than takes the lowest available place in that column.

Columns are numbered from 0 up to (excluded) the width of the grid.

## The referee

The `referee` is an executable that will take the paths (relative or absolute) of each of the two
connect N players as its arguments.

The `referee` will be executing the two players and capture their standard input and output,
but leaves the standard untouched.

Each player will then receive information from the `referee` through their `stdin` (standard input),
and communicate back to the `referee` through their `stdout` (standard output).


## The protocol

The protocol is the manner with which your program is expected to behave,
any mistake when communicating to the referee will be counted as a fault
and the victory will be attributed to the opposing player.

The protocol has to steps *setup* and *game* :   
- The *setup* will describe the rules of the connect N. 4 different informations are shared :   
`width`, `height`, `connect number` for winning, `player's position`, `total time`, `time gain per move`. 
- The *game* will be the arbitrated exchange between players.

| player a | player b | comment             |
|----------|----------|---------------------|
| -> 7     | -> 7     | board has width 7  	|
| -> 6     | -> 6     | board has height 6  |
| -> 4     | -> 4     | winning length of 4 |
| -> 2     | -> 1     | player b starts     |
| -> 10000 | -> 10000 | total time          |
| -> 100   | -> 100   | time gain           |
| waits... | X ->     | player b sends X    |
| -> X     | waits... | player a gets X     |
| Y ->     | waits... | player a sends Y    |
| waits... | -> Y     | player b gets Y     |
|    ..    |    ..    | etc ...             |

## Players

A player is an executable will communicate

TODO: fill authorized and an authorized behaviour


## Messages

A message is a single unsigned integer that fits into `16 bit`.

The existing messages are (in order):
- **width**: width / number of columns of the game board,
- **height**: width / number of columns of the game board,
- **winning length**: number of pieces of your color to win the game,
- **player order**: 1 if you are the first player 2 if you are the second player,
- **column played**: column played by you or you opponent where `0 <= column < height`
and a place is free at the top of the column that is no more than *height* pieces have been played in that column.
