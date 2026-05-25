# Tests

---
## Estructura
```
tests/
├── matrices/
│   ├── int_random/       # Enteros aleatorios en [-500, 500]
│   ├── real_random/      # Reales en [0, 1]
│   ├── dispersa/         # Dispersas (90% ceros)
│   └── simetrica/        # Simétricas
├── results/            # CSVs con resultados de los experimentos
├── generator.cpp       # Generador de matrices
├── uhr.cpp             # Experimentos usando el algoritmo clásico y el de Strassen
├── uhr_hybrid.cpp      # Experimentos usando el algoritmo híbrido
└── README.md
```

---

## Modificaciones a uhr

El archivo `uhr.cpp` original fue obtenido del repositorio [uhr](https://github.com/leonardlover/uhr)
y modificado de la siguiente forma:

1. **Paso multiplicativo:** el `for` de iteración sobre `n` fue cambiado de aditivo (`n += step`) a multiplicativo (`n *= step`), para poder iterar sobre potencias de 2.

2. **Argumentos extra:** se agregaron dos argumentos adicionales (`algoritmo` e `instancia`) para poder seleccionar el algoritmo y el tipo de instancia desde la línea de comandos, sin necesidad de recompilar. La validación de `validate_input` fue ajustada para aceptar 8 argumentos en vez de 6.


El archivo `uhr_hybrid.cpp` es una versión separada para el algoritmo híbrido, que recibe adicionalmente el parámetro `n0` y no usa `validate_input`.

---

## 1. Generar las matrices

Compilar y ejecutar el generador desde la carpeta `tests/`:

```bash
g++ -std=c++17 -o generator.exe generator.cpp
.\generator.exe
```

Esto crea las carpetas `matrices/<tipo>/` y genera los archivos `A_<n>.txt` y `B_<n>.txt` para cada tipo de instancia que se quiere testear y para cada $n \in \{4, 8, 16, 32, 64, 128, 256, 512, 1024\}$.

---

## 2. Compilar

Desde la carpeta `tests/`:

```bash
g++ -std=c++17 -O0 -o uhr.exe uhr.cpp
g++ -std=c++17 -O0 -o uhr_hybrid.exe uhr_hybrid.cpp
```

---

## 3. Ejecutar los experimentos

### Algoritmo clásico y de Strassen

```bash
.\uhr.exe <archivo.csv> <runs> <lower> <upper> <step> <algoritmo> <instancia>
```

Donde:
- `<archivo.csv>`: nombre del archivo de salida en `results/`
- `<runs>`: número de repeticiones por tamaño
- `<lower>`: tamaño mínimo de matriz
- `<upper>`: tamaño máximo de matriz
- `<step>`: factor multiplicativo (usar 2 para potencias de 2)
- `<algoritmo>`: `clasico` o `strassen`
- `<instancia>`: `int_random`, `real_random`, `dispersa` o `simetrica`

Ejemplo para replicar todos los experimentos:

```bash
.\uhr.exe results/clasico_int_random.csv 32 4 1024 2 clasico int_random
.\uhr.exe results/clasico_real_random.csv 32 4 1024 2 clasico real_random
.\uhr.exe results/clasico_dispersa.csv 32 4 1024 2 clasico dispersa
.\uhr.exe results/clasico_simetrica.csv 32 4 1024 2 clasico simetrica
.\uhr.exe results/strassen_int_random.csv 32 4 1024 2 strassen int_random
.\uhr.exe results/strassen_real_random.csv 32 4 1024 2 strassen real_random
.\uhr.exe results/strassen_dispersa.csv 32 4 1024 2 strassen dispersa
.\uhr.exe results/strassen_simetrica.csv 32 4 1024 2 strassen simetrica
```

### Algoritmo Híbrido

```bash
.\uhr_hybrid.exe <archivo.csv> <runs> <lower> <upper> <step> <instancia> <n0>
```

Donde `<n0>` es el umbral a partir del cual se usa Strassen en vez del clásico.

Ejemplo:

```bash
.\uhr_hybrid.exe results/hybrid_int_random.csv 32 4 512 2 int_random
```

---