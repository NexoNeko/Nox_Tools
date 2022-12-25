# Nox_Rsg
This is a simple RandomStringGenerator based on the 52 factorial principle.

This program will generate a string of 51 characters (from A to Z and a to z). Some characters might repeat 1 time randomly, this is all to ensure randomness and minimize repetitions.


Potentially, this could be turned into an RNG, by converting the values to integers, or even assign a singular value to a group of chars.
 
 For example, to make a 6 sided die, you'd need to divide all the chars in groups of 8 chars and assign 1 return value to each group to ensure an uniform distribution.
 Since you'd get a 4-character leftover, make it reroll every time it lands on the 4 character group, and you got quite a fair dice roller, theorically with an 1/6 chance.


This program is not supposed to print the same string twice, yet sometimes it does, you can appreciate this in the SAMPLE_OUTPUT file, 2 strings repeated in a series of 1050 strings. The first string at line @480, with it's doppleganger @785 and the second line @374, it's doppleganger @552.
