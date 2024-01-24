# HdeWrapper

## What's so cool about that?
it is a very interesting wrapper and tool for internal projects, notably on games such as TheFinals where most engine related ptr are encrypted. 

## What's the point?
you can replicate the steps taken for you to get the offset on IDA to get this dynamically.

theres also a minimal offset range for the nearest instruction

## Any limits?
this version only supports MOV for now, the original concept used capstone and is still available i think but this project ismore complete

this example used uworld and the lib was originally based off capstone which i switched to hde later for lightweight lib and capstone INSN bugging in some case

but for example for GWorld it gets PUSH into a CPU register which then gets transformed to a variable from ASM to compiletime which then gets you the variable that the function returns

## Wow so its not full at all..
i made this project in about 30 minutes

every todo on the list is going to be implemented as soon as i have time
