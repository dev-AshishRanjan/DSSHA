# DSSHA: Dynamic-Sized Secure Hash Algorithm with Memory-Hard Capabilities for Enhanced Cryptographic Security

DSSHA is a secure hash algorithm that randomized the bits using generated pool of bits. It generates a set of bits, and later, it selects the generated bits to form
the randomized secure hash value.

## DSSHA-1D

It is a fast hash algorithm of DSSHA but it lacks randomization. Moreover, it does not features memory-hardness.

## DSSHA-2D

It is a slower hash algorithm than DSSHA-1D. DSSHA-2D hash three phases, namely, dimension, filling and retrieval. DSSHA-2D decides the dimensions of vector in the dimension phase,
and the dimensions are X and Y. DSSHA-2D generates set of pseudo-random bits and filled it in a bit vector in the filling phase. The retrieval phase selects n bits
from bit vectors pseudo-randomly which forms the randomized secure hash value.

## DSSHA-3D

It is a slower hash algorithm than DSSHA-2D. It is similar except the bit vector. DSSHA-3D uses three dimensional bit vector, and the dimensions are X, Y, and Z.
It is more secure than DSSHA-1D and DSSHA-2D.

## Compilation

To compile DSSHA-1D, `gcc DSSHA-1D.c -o DSSHA1D` and run it as `./DSSHA1D`

To compile DSSHA-2D, `gcc DSSHA-2D.c -o DSSHA2D -lm` and run it as `./DSSHA2D`

To compile DSSHA-2D, `gcc DSSHA-3D.c -o DSSHA3D -lm` and run it as `./DSSHA3D`

To compile DSSHA(Interactive Menu), `gcc ./interface/DSSHA.c -o DSSHA -lm` and run it as `./DSSHA`

## Murmur2 vs Murmur3

Here are the key differences between **MurmurHash2** and **MurmurHash3**:

| **Aspect**         | **MurmurHash2**                               | **MurmurHash3**                                                       |
| ------------------ | --------------------------------------------- | --------------------------------------------------------------------- |
| **Release Year**   | Older version, introduced earlier.            | Modernized version, introduced later.                                 |
| **Output Size**    | Fixed 32-bit or 64-bit.                       | Supports 32-bit, 128-bit, and variable-sized outputs.                 |
| **Performance**    | Faster but less secure for modern use cases.  | Slower but provides better mixing and security.                       |
| **Mixing Quality** | Weaker mixing, prone to some hash collisions. | Improved mixing, better avalanche behavior.                           |
| **Security**       | Vulnerable to some hash collision attacks.    | More resilient against collision attacks.                             |
| **Finalization**   | Simplistic, less thorough.                    | More thorough and complex finalization.                               |
| **Use Case**       | Suitable for basic hashing and older systems. | Preferred for cryptographic or modern systems needing robust hashing. |

In short:

- Use **MurmurHash2** for speed and simplicity in non-critical tasks.
- Use **MurmurHash3** for better distribution, security, and variable-sized output.

## Citation

```
@misc{github:2024/DSSHA,
      author = {Ripon Patgiri and Kumar Ashish Ranjan and Jugya Kamal Gogoi and Tolemy Kashyap},
      title = {DSSHA: Dynamic-Sized Secure Hash Algorithm},
      howpublished = {Github, FYP NIT Silchar:2024/27},
      wherepublished = {GitHub},
      whenpublished = {FYP, NIT Silchar},
      year = {2024},
      note = {\url{https://github.com/dev-AshishRanjan/DSSHA}},
      url = {https://github.com/dev-AshishRanjan/DSSHA}
}
```
