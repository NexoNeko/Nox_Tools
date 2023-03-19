# Gem roller

This program is part of my RPG-companion series, as such most of it's functionality depends on Nox_RTD for die rolls.

At each roll, the program will return a varying amount of jewels of varying quality and value.
The quantity, quality and value are chosen according to the following tables:

### Rarity:
Rarity will be treated as a prefix, except for the 'Gem' rarity, which will be treated as a suffix.
Type| Base value in gold pieces | Quantity |
--- | --- | --- | 
Ornamental| 10 | 1d10 |
Semiprecious| 50 | 1d8 |
Fancy | 100 | 1d6 |
Precious | 500 | 1d4 |
Gem | 1000 | 1d2 |

### Value adjustement:
1d12| Value adjustement |
--- | --- |
2| Next Lower Value Row |
3| 1/2 |
4 | 3/4 |
5 - 9 | Normal value |
10 | 1.5 times |
11 | 2 times |
12 | Next Higher Value Row |

### Gem types
For simplicity, the rarity of the gems is 1/15 for each.

Chlorastrolite, Malachite, Aventurine, Rhodonite,Amethyst, Fluorospar, Garnet, Alexandrite, Topaz, Heliotrope, Sapphire, Diamond, Fire Opal, Ruby, Emerald.


## Installation

Just run Gem_roller.exe on windows. 

This software is not compatible with linux at the momment.

To compile this program locally, compile all C files together:
```cmd
  gcc *.c
```

[![GPL 3.0 License](https://img.shields.io/badge/License-GPL%203.0-yellow.svg?style=plastic)](https://www.gnu.org/licenses/gpl-3.0.en.html)

[![C99 compilant](https://img.shields.io/badge/C99-ISO/IEC%209899:1999-blue.svg?style=plastic&logo=c%2B%2B)](https://en.cppreference.com/w/c/99)
