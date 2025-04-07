# Linuxcnc_Kinematics


### Matrix


The vector dot product is a way to measure how much two vectors point in the same direction.


For vectors A = [a₁, a₂, a₃] and B = [b₁, b₂, b₃]:

---

A · B = a₁×b₁ + a₂×b₂ + a₃×b₃

A = [1, 2, 3]
B = [4, 5, 6]

Dot product = 1×4 + 2×5 + 3×6 = 4 + 10 + 18 = 32

Large positive → same direction

---

A = [1, 0]
B = [0, 1]

Dot = 1×0 + 0×1 = 0

Zero → perpendicular


---

A = [1, 2]
B = [-1, -2]

Dot = 1×(-1) + 2×(-2) = -1 - 4 = -5

Negative → opposite direction

---


### dot product properties


Commutative

A · B = B · A

Distributive over addition

A · (B + C) = A · B + A · C


Scalar multiplication

(kA) · B = k(A · B) = A . (kB)

Zero vector

A · 0 = 0

Orthogonal (perpendicular) vectors

A · B = 0  → A ⟂ B

Angle relation

A · B = |A||B|cos(θ)

Let me know if you want proofs or examples.


Self dot product = squared magnitude

A · A = |A|²

0 . A = 0



Projection relation

A · B = |A| * |B| * cos(θ) → used to project B onto A


cos(θ) = (A * B) / (|A| * |B|)



Invariance under rotation (in Euclidean space)

Dot product stays the same under rotation of coordinate axes (if both vectors rotate equally).



Bilinear property

Dot product is linear in both arguments:
(A + B) · C = A · C + B · C




Symmetric in real space

A · B = B · A



Dot product of unit vectors: (very useful in angle calculations)

If |A| = |B| = 1, then:

A · B = cos(θ)


Dot product is coordinate system independent
As long as the basis is orthonormal.


Associative with scalars, not with vectors

Valid: k(A · B)

❌ Invalid: A · (B · C) → this is not defined.



Used in checking vector alignment

If A · B > 0 → same direction

If A · B < 0 → opposite

If A · B = 0 → orthogonal or perpendicular


Perpendicular → more common in geometry.

Orthogonal → often used in linear algebra, vector math, and higher dimensions.

Both mean the angle between the vectors is 90°.






The notation `|A|` is called:

### ✅ **Absolute value** (for scalars)  
### ✅ **Magnitude** or **Modulus** (for vectors)

---

But when written as `‖A‖` (double bars), it's more formally called:

### ✅ **Norm** notation  
Especially for vector or matrix norms.

---

### 🔹 Summary:
| Notation | Name           | Used for         |
|----------|----------------|------------------|
| `|a|`     | Absolute Value | Scalar (number)  |
| `|A|`     | Magnitude      | Vector (casual)  |
| `‖A‖`     | Norm           | Vector (formal)  |





### 📌 **Magnitude of a Vector — Simple Explanation**

The **magnitude** of a vector means **how long** or **how big** the vector is. It’s like measuring the length of a line.

 how to find magnitude |A| for 1D, 2D, and 3D vectors:

---


1D Vector:


```
A = [a]
|A| = |a|   → just the absolute value

```

### ✅ **Formula**

For a 2D vector:  
**v = (x, y)**  
**‖v‖ = √(x² + y²)**

For a 3D vector:  
**v = (x, y, z)**  
**‖v‖ = √(x² + y² + z²)**

---

### 🧮 **Example (2D)**  
Vector **v = (3, 4)**  
Magnitude = √(3² + 4²)  
      = √(9 + 16)  
      = √25  
      = **5**

---

### 🧮 **Example (3D)**  
Vector **v = (1, 2, 2)**  
Magnitude = √(1² + 2² + 2²)  
      = √(1 + 4 + 4)  
      = √9  
      = **3**



A = [3, 4, 12]
|A| = √(3² + 4² + 12²) = √(9 + 16 + 144) = √169 = 13




Let me know if you want graphical explanation too!




Each **column** represents how B's axes project onto A's axes:

```
         Bx        By        Bz
A = [   r11      r12      r13   ]  ← Ax
    [   r21      r22      r23   ]  ← Ay
    [   r31      r32      r33   ]  ← Az
```

So:

- Column 1 `[r11 r21 r31]ᵀ` = **Bx in A's frame**
- Column 2 `[r12 r22 r32]ᵀ` = **By in A's frame**
- Column 3 `[r13 r23 r33]ᵀ` = **Bz in A's frame**

Each **row** tells how A's axis sees B's axes.

Use this matrix to **rotate a vector from B to A** like:

```math
v_A = R * v_B
```




- `r11 = dot(Ax, Bx)` → how much **B’s X** points along **A’s X**
- `r12 = dot(Ax, By)` → how much **B’s Y** points along **A’s X**
- `r13 = dot(Ax, Bz)` → how much **B’s Z** points along **A’s X**

- `r21 = dot(Ay, Bx)` → how much **B’s X** points along **A’s Y**
- `r22 = dot(Ay, By)` → etc.
- `r23 = dot(Ay, Bz)`

- `r31 = dot(Az, Bx)`
- `r32 = dot(Az, By)`
- `r33 = dot(Az, Bz)`

So the whole matrix is just:

```
R = [ dot(Ax, Bx)  dot(Ax, By)  dot(Ax, Bz) ]
    [ dot(Ay, Bx)  dot(Ay, By)  dot(Ay, Bz) ]
    [ dot(Az, Bx)  dot(Az, By)  dot(Az, Bz) ]
```






simple 3D example with clear values.

---

### Let's define two coordinate frames:

#### Frame A (standard basis):
```
Ax = [1, 0, 0]
Ay = [0, 1, 0]
Az = [0, 0, 1]
```

#### Frame B (rotated 90° around Z-axis):
```
Bx = [0, 1, 0]
By = [-1, 0, 0]
Bz = [0, 0, 1]
```

---

### Now let's compute `r11 = dot(Ax, Bx)`:

```text
Ax ⋅ Bx = [1, 0, 0] ⋅ [0, 1, 0]
        = (1×0) + (0×1) + (0×0)
        = 0
```

So, `r11 = 0`

---

### Full Rotation Matrix R = A relative to B:

```
r11 = dot(Ax, Bx) = 0
r12 = dot(Ax, By) = [1,0,0] ⋅ [-1,0,0] = -1
r13 = dot(Ax, Bz) = [1,0,0] ⋅ [0,0,1] = 0

r21 = dot(Ay, Bx) = [0,1,0] ⋅ [0,1,0] = 1
r22 = dot(Ay, By) = [0,1,0] ⋅ [-1,0,0] = 0
r23 = dot(Ay, Bz) = [0,1,0] ⋅ [0,0,1] = 0

r31 = dot(Az, Bx) = [0,0,1] ⋅ [0,1,0] = 0
r32 = dot(Az, By) = [0,0,1] ⋅ [-1,0,0] = 0
r33 = dot(Az, Bz) = [0,0,1] ⋅ [0,0,1] = 1
```

---

### Final rotation matrix:
```
R = [  0  -1   0 ]
    [  1   0   0 ]
    [  0   0   1 ]
```

This is the standard rotation matrix for **90° rotation about Z-axis**.






- Rotation matrix **R = orientation of B relative to A**
- Each element `rij` is **dot(Ai, Bj)** → how A's axis `i` sees B's axis `j`

And your matrix:

```
        Bx  By  Bz
     ┌             ┐
R = [ 0  -1   0 ]  ← Ax
    [ 1   0   0 ]  ← Ay
    [ 0   0   1 ]  ← Az
     └             ┘
```

Perfectly matches a 90° rotation of B around Z-axis in A’s view.



Perfect summary ✅

- **Matrix = B’s axes in A’s frame**
- **To convert**:
  - From **B → A**: `v_A = R * v_B`
  - From **A → B**: `v_B = Rᵀ * v_A` (since rotation matrices are orthogonal)







rotate **Frame B by 1° around Z-axis** (counter-clockwise) relative to Frame A.

---

### 🔹 Rotation by θ = 1° around Z-axis:

Use standard Z-rotation matrix:

```
Bx = [cos(1°), sin(1°), 0]
By = [-sin(1°), cos(1°), 0]
Bz = [0,       0,      1]
```

### 🔸 Approximate values:
- cos(1°) ≈ 0.9998477  
- sin(1°) ≈ 0.0174524

---

### 🔹 Frame B axes in A’s coordinates:

```
Bx = [  0.9998477,  0.0174524,  0 ]
By = [ -0.0174524,  0.9998477,  0 ]
Bz = [  0,          0,          1 ]
```

---

### 🔹 Rotation matrix R (B relative to A):

```
        Bx         By         Bz
     ┌                              ┐
R = [ 0.9998477  -0.0174524   0 ] ← Ax  
    [ 0.0174524   0.9998477   0 ] ← Ay  
    [ 0           0           1 ] ← Az  
     └                              ┘
```

✅ This is a 1° rotation about Z-axis. You can now use this to rotate vectors from B to A.





Alright! Here's the **full result** with:

- Sample Frame A (standard)
- Frame B (rotated 1° around Z)
- Full dot product breakdown for the rotation matrix

---

### 🔹 Frame A (standard basis):
```
Ax = [1, 0, 0]
Ay = [0, 1, 0]
Az = [0, 0, 1]
```

---

### 🔹 Frame B (rotated 1° CCW around Z):
```
Bx = [ cos(1°), sin(1°), 0 ] ≈ [ 0.9998477, 0.0174524, 0 ]
By = [−sin(1°), cos(1°), 0 ] ≈ [−0.0174524, 0.9998477, 0 ]
Bz = [      0,       0, 1 ]
```

---

### 🔹 Rotation matrix R = B relative to A:

Each element is `dot(Ai, Bj)`:

#### Row 1 → Ax = [1, 0, 0]
```
r11 = dot(Ax, Bx) = [1, 0, 0] ⋅ [ 0.9998477, 0.0174524, 0 ] = 0.9998477
r12 = dot(Ax, By) = [1, 0, 0] ⋅ [-0.0174524, 0.9998477, 0 ] = -0.0174524
r13 = dot(Ax, Bz) = [1, 0, 0] ⋅ [ 0,         0,        1 ] = 0
```

#### Row 2 → Ay = [0, 1, 0]
```
r21 = dot(Ay, Bx) = [0, 1, 0] ⋅ [ 0.9998477, 0.0174524, 0 ] = 0.0174524
r22 = dot(Ay, By) = [0, 1, 0] ⋅ [-0.0174524, 0.9998477, 0 ] = 0.9998477
r23 = dot(Ay, Bz) = [0, 1, 0] ⋅ [ 0,         0,        1 ] = 0
```

#### Row 3 → Az = [0, 0, 1]
```
r31 = dot(Az, Bx) = [0, 0, 1] ⋅ [ 0.9998477, 0.0174524, 0 ] = 0
r32 = dot(Az, By) = [0, 0, 1] ⋅ [-0.0174524, 0.9998477, 0 ] = 0
r33 = dot(Az, Bz) = [0, 0, 1] ⋅ [ 0,         0,        1 ] = 1
```

---

### ✅ Final Rotation Matrix R:
```
        Bx           By          Bz
     ┌                                  ┐
R = [ 0.9998477   -0.0174524    0 ] ← Ax  
    [ 0.0174524    0.9998477    0 ] ← Ay  
    [ 0            0            1 ] ← Az  
     └                                  ┘
```

Let me know if you want a diagram or how to use this to rotate a vector!





To find the **length of the vector** between two points A(2,2) and B(5,5):

Use the distance formula:

```
||AB|| = √[(x₂ − x₁)² + (y₂ − y₁)²]
       = √[(5 − 2)² + (5 − 2)²]
       = √[3² + 3²]
       = √[9 + 9] = √18 ≈ 4.24
```

✅ So the length is approximately **4.24 units**.



Points: A(1,1), B(2,2)

Length:

```
||AB|| = √[(2−1)² + (2−1)²]
       = √[1² + 1²]
       = √[1 + 1] = √2 ≈ 1.41
```

✅ Length ≈ **1.41 units**.



The **square diagonal formula** (from one corner to the opposite) is:

```
d = √(a² + a²) = a√2
```

Where `a` is the side length of the square.

✅ Example: If `a = 5`, then diagonal = `5√2 ≈ 7.07` units.



If `a = 1`, then:

```
diagonal = 1 × √2 ≈ 1.41 units
``` ✅






EXTRA

```
https://en.wikipedia.org/wiki/Rotation_of_axes_in_two_dimensions
https://www.mathworks.com/help/phased/ref/rotz.html

https://math.stackexchange.com/questions/4294253/3d-rotation-about-z-axis
https://math.stackexchange.com/questions/4291247/3d-rotation-about-z-axis


https://www.youtube.com/watch?v=nOx-IOc12vk&ab_channel=MichelvanBiezen

http://pd.chem.ucl.ac.uk/pdnn/symm1/rotate2.htm


https://byjus.com/maths/magnitude-of-a-vector/
https://byjus.com/maths/dot-product-of-two-vectors/
```