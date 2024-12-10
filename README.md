# DSSHF: Dynamic-Sized Secure Hash Function with Memory-Hard Capabilities for Enhanced Cryptographic Security

DSSHF is a secure hash algorithm that randomized the bits using generated pool of bits. It generates a set of bits, and later, it selects the generated bits to form
the randomized secure hash value.

## DSSHF-1D

It is a fast hash algorithm of DSSHF but it lacks randomization. Moreover, it does not features memory-hardness.

## DSSHF-2D

It is a slower hash algorithm than DSSHF-1D. DSSHF-2D hash three phases, namely, dimension, filling and retrieval. DSSHF-2D decides the dimensions of vector in the dimension phase,
and the dimensions are X and Y. DSSHF-2D generates set of pseudo-random bits and filled it in a bit vector in the filling phase. The retrieval phase selects n bits
from bit vectors pseudo-randomly which forms the randomized secure hash value.

## DSSHF-3D

It is a slower hash algorithm than DSSHF-2D. It is similar except the bit vector. DSSHF-3D uses three dimensional bit vector, and the dimensions are X, Y, and Z.
It is more secure than DSSHF-1D and DSSHF-2D.

## Compilation

To compile DSSHF-1D, `gcc dsshf-1D.c -o DSSHF1D` and run it as `./DSSHF1D`

To compile DSSHF-2D, `gcc dsshf-2D.c -o DSSHF2D -lm` and run it as `./DSSHF2D`

To compile DSSHF-2D, `gcc dsshf-3D.c -o DSSHF3D -lm` and run it as `./DSSHF3D`

To compile DSSHF(Interactive Menu), `gcc ./interface/dsshf.c -o DSSHF -lm` and run it as `./DSSHF`


## Murmur2 vs Murmur3
Here are the key differences between **MurmurHash2** and **MurmurHash3**:

| **Aspect**            | **MurmurHash2**                                | **MurmurHash3**                                |
|-----------------------|-----------------------------------------------|-----------------------------------------------|
| **Release Year**      | Older version, introduced earlier.            | Modernized version, introduced later.         |
| **Output Size**       | Fixed 32-bit or 64-bit.                       | Supports 32-bit, 128-bit, and variable-sized outputs. |
| **Performance**       | Faster but less secure for modern use cases.  | Slower but provides better mixing and security. |
| **Mixing Quality**    | Weaker mixing, prone to some hash collisions. | Improved mixing, better avalanche behavior.   |
| **Security**          | Vulnerable to some hash collision attacks.    | More resilient against collision attacks.     |
| **Finalization**      | Simplistic, less thorough.                    | More thorough and complex finalization.       |
| **Use Case**          | Suitable for basic hashing and older systems. | Preferred for cryptographic or modern systems needing robust hashing. |

In short:  
- Use **MurmurHash2** for speed and simplicity in non-critical tasks.  
- Use **MurmurHash3** for better distribution, security, and variable-sized output.


## Citation

```
@misc{github:2024/DSSHF,
      author = {Kumar Ashish Ranjan and Jugya Kamal Gogoi and Tolemy Kashyap},
      title = {DSSHF: Dynamic-Sized Secure Hash Function},
      howpublished = {Github, FYP NIT Silchar:2024/27},
      wherepublished = {GitHub},
      whenpublished = {FYP, NIT Silchar},
      year = {2024},
      note = {\url{https://github.com/dev-AshishRanjan/DSSHF}},
      url = {https://github.com/dev-AshishRanjan/DSSHF}
}
```
