# Classic CS Algorithms

A curriculum devoted to number theory, modular arithmetic, and combinatorial games.

### 🔢 Number Theory
- **Extended Euclidean Algorithm**: GCD, LCM (`problem_ee.c`)
- **Diophantine Equations**: Solving $ax + by = c$ (`problem_de.c`)
- **Number Systems**: Base conversion (`problem_ns.c`)
- **Factorial Number System**: Representation and conversion (`problem_fs.c`)
- **Continued Fractions**: Expansion and approximation (`problem_cf.c`)

### 📉 Modular Arithmetic & Matrices
- **Modular Exponentiation**: Fast power algorithms (`problem_mf.c`)
- **Fibonacci Sequence**:
  - Fast $N$-th Fibonacci number via matrices (`problem_fm.c`)
  - Pisano periods (`problem_pp.c`)
  - Zeckendorf's theorem (`problem_sf.c`)
  - Fibonacci Nim bot (`problem_hwf.c`)

## 🛠 Build & Test

The project uses `make` for building and `check` library for unit testing.

# Run unified Fibonacci tests (Game, Zeckendorf, Matrix Fibo)
make fibo_all

# Clean build artifacts
make clean

## 📝 Requirements
- GCC / Clang (C17 standard)
- `libcheck` (for running tests)
