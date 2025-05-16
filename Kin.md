# Linuxcnc_Kinematics



**angle addition formulas** for sine and cosine:

$$
\cos(\theta_1 + \theta_2) = \cos\theta_1 \cos\theta_2 - \sin\theta_1 \sin\theta_2
$$

$$
\sin(\theta_1 + \theta_2) = \sin\theta_1 \cos\theta_2 + \cos\theta_1 \sin\theta_2
$$

Using these:

$$
T_{12} =
\begin{bmatrix}
\cos(\theta_1 + \theta_2) & -\sin(\theta_1 + \theta_2) & 0 & L_1 \cos\theta_1 + L_2 \cos(\theta_1 + \theta_2) \\
\sin(\theta_1 + \theta_2) & \cos(\theta_1 + \theta_2) & 0 & L_1 \sin\theta_1 + L_2 \sin(\theta_1 + \theta_2) \\
0 & 0 & 1 & 0 \\
0 & 0 & 0 & 1
\end{bmatrix}
$$




Here’s the **full list of angle addition and subtraction formulas** for sine, cosine, tangent, and cotangent:

---

### ✅ **1. Sine Addition and Subtraction**

$$
\sin(A + B) = \sin A \cos B + \cos A \sin B
$$

$$
\sin(A - B) = \sin A \cos B - \cos A \sin B
$$

---

### ✅ **2. Cosine Addition and Subtraction**

$$
\cos(A + B) = \cos A \cos B - \sin A \sin B
$$

$$
\cos(A - B) = \cos A \cos B + \sin A \sin B
$$

---

### ✅ **3. Tangent Addition and Subtraction**

$$
\tan(A + B) = \frac{\tan A + \tan B}{1 - \tan A \tan B}
$$

$$
\tan(A - B) = \frac{\tan A - \tan B}{1 + \tan A \tan B}
$$

---

### ✅ **4. Cotangent Addition and Subtraction**

$$
\cot(A + B) = \frac{\cot A \cot B - 1}{\cot A + \cot B}
$$

$$
\cot(A - B) = \frac{\cot A \cot B + 1}{\cot B - \cot A}
$$






Sure! Here's the full list of **double-angle** and **half-angle** formulas for sine, cosine, tangent, and cotangent.

---

### 🔁 **Double-Angle Formulas**

#### ✅ Sine

$$
\sin(2A) = 2 \sin A \cos A
$$

#### ✅ Cosine

$$
\cos(2A) = \cos^2 A - \sin^2 A = 2\cos^2 A - 1 = 1 - 2\sin^2 A
$$

#### ✅ Tangent

$$
\tan(2A) = \frac{2\tan A}{1 - \tan^2 A}
$$

#### ✅ Cotangent

$$
\cot(2A) = \frac{\cot^2 A - 1}{2\cot A}
$$

---

### 🌓 **Half-Angle Formulas**

> Use ± depending on the quadrant of the angle.

#### ✅ Sine

$$
\sin\left(\frac{A}{2}\right) = \pm\sqrt{\frac{1 - \cos A}{2}}
$$

#### ✅ Cosine

$$
\cos\left(\frac{A}{2}\right) = \pm\sqrt{\frac{1 + \cos A}{2}}
$$

#### ✅ Tangent

$$
\tan\left(\frac{A}{2}\right) = \pm\sqrt{\frac{1 - \cos A}{1 + \cos A}} = \frac{\sin A}{1 + \cos A} = \frac{1 - \cos A}{\sin A}
$$

#### ✅ Cotangent

$$
\cot\left(\frac{A}{2}\right) = \pm\sqrt{\frac{1 + \cos A}{1 - \cos A}} = \frac{\sin A}{1 - \cos A} = \frac{1 + \cos A}{\sin A}
$$

Let me know if you also want **product-to-sum** or **sum-to-product** identities.





Here are the full **Product-to-Sum** and **Sum-to-Product** identities for sine and cosine:

---

### 🔁 **Product-to-Sum Identities**

These convert products of sines and cosines into sums.

#### ✅ $\sin A \sin B$

$$
\sin A \sin B = \frac{1}{2} \left[ \cos(A - B) - \cos(A + B) \right]
$$

#### ✅ $\cos A \cos B$

$$
\cos A \cos B = \frac{1}{2} \left[ \cos(A - B) + \cos(A + B) \right]
$$

#### ✅ $\sin A \cos B$

$$
\sin A \cos B = \frac{1}{2} \left[ \sin(A + B) + \sin(A - B) \right]
$$

#### ✅ $\cos A \sin B$

$$
\cos A \sin B = \frac{1}{2} \left[ \sin(A + B) - \sin(A - B) \right]
$$

---

### 🔃 **Sum-to-Product Identities**

These convert sums or differences into products.

#### ✅ $\sin A + \sin B$

$$
\sin A + \sin B = 2 \sin\left( \frac{A + B}{2} \right) \cos\left( \frac{A - B}{2} \right)
$$

#### ✅ $\sin A - \sin B$

$$
\sin A - \sin B = 2 \cos\left( \frac{A + B}{2} \right) \sin\left( \frac{A - B}{2} \right)
$$

#### ✅ $\cos A + \cos B$

$$
\cos A + \cos B = 2 \cos\left( \frac{A + B}{2} \right) \cos\left( \frac{A - B}{2} \right)
$$

#### ✅ $\cos A - \cos B$

$$
\cos A - \cos B = -2 \sin\left( \frac{A + B}{2} \right) \sin\left( \frac{A - B}{2} \right)
$$




https://www.youtube.com/watch?v=8CGpu9y4_sE&ab_channel=LeslieGlen

https://www.youtube.com/watch?v=9R5Nz1eYddM&ab_channel=ProfessorLeonard

