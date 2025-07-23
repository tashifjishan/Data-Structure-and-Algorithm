# 🔁 Infix to Postfix Conversion (Shunting Yard Algorithm)

## 🧠 Main Idea:
Use a **stack** to hold operators and parentheses. Output the final result in **postfix** (Reverse Polish Notation), where parentheses are not needed.

---

## 📋 Algorithm Steps:

1. For each **token** in the infix expression:
    - If it is an **operand** (number or variable):
        - Append it to the output.
    - If it is an **operator** (`+`, `-`, `*`, `/`):
        - While the **top of the stack** has **greater or equal precedence** and is **not a `(`**:
            - Pop from the stack to the output.
        - Push the current operator onto the stack.
    - If it is a **left parenthesis `(`**:
        - Push it onto the stack.
    - If it is a **right parenthesis `)`**:
        - Pop from the stack to output **until `(` is found**.
        - Discard the `(`.

2. After all tokens are processed:
    - Pop any **remaining operators** from the stack to the output.

---

## 🧮 Operator Precedence Table

| Operator | Precedence | Associativity |
|----------|------------|---------------|
| `*`, `/` | 2          | Left          |
| `+`, `-` | 1          | Left          |
| `(`      | -          | -             |

---


---

## 📎 Notes:
- This method assumes the infix expression is tokenized with **spaces** (e.g., `2 * 4` not `2*4`).
- It works with **only `+`, `-`, `*`, `/`, `(`, and `)`** operators.
- You can extend this to support variables or exponentiation (`^`) by modifying precedence and associativity.
