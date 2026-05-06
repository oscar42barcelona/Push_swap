*Este proyecto ha sido creado como parte del currículo de 42 por osuarez-, jgarcia4.*

# push_swap

## 📖 Descripción

**push_swap** es un proyecto de algoritmia que consiste en ordenar una secuencia de enteros únicamente mediante un conjunto restringido de operaciones sobre dos pilas, **A** y **B**, minimizando el número de movimientos.

El programa recibe la lista de enteros como argumentos, imprime en `stdout` la secuencia de operaciones que ordena la pila A de menor a mayor, dejando la pila B vacía.

### 🔧 Operaciones disponibles

| Operación | Descripción |
| :---: | :--- |
| `sa` | Intercambia los dos primeros elementos de A. |
| `sb` | Intercambia los dos primeros elementos de B. |
| `ss` | `sa` y `sb` simultáneamente. |
| `pa` | Mueve el elemento superior de B a la cima de A. |
| `pb` | Mueve el elemento superior de A a la cima de B. |
| `ra` | Rota A hacia arriba: el primero pasa al final. |
| `rb` | Rota B hacia arriba. |
| `rr` | `ra` y `rb` simultáneamente. |
| `rra` | Rota A hacia abajo: el último pasa al inicio. |
| `rrb` | Rota B hacia abajo. |
| `rrr` | `rra` y `rrb` simultáneamente. |

---

### ⚙️ Algoritmos y Estructura Interna

La pieza central del diseño es el **índice de desorden**, que guía la elección automática de algoritmo en el modo adaptativo.

#### 1. Índice de Desorden (`compute_disorder`)

Mide la fracción de pares invertidos sobre el total de pares posibles:

```
disorder = inversiones / (n * (n-1) / 2)
```

Un valor de `0.0` indica que la pila ya está ordenada; `1.0` indica orden completamente inverso. Este índice es O(n²) de calcular, pero se usa una sola vez antes de ordenar.

#### 2. Algoritmo Adaptativo (`adaptive_sort`)

Selecciona automáticamente el algoritmo óptimo según el régimen de desorden, siguiendo los umbrales del subject:

| Rango de desorden | Algoritmo elegido | Complejidad |
| :---: | :---: | :---: |
| `disorder < 0.2` | `selection_sort` | O(n²) |
| `0.2 ≤ disorder < 0.5` | `chunk_sort` | O(n√n) |
| `disorder ≥ 0.5` | `radix_sort` | O(n log n) |

La justificación: para entradas casi ordenadas (pocas inversiones), `selection_sort` es muy eficiente en la práctica porque los elementos ya están cerca de su posición final. Para desorden medio, el método de chunks explota la localidad. Para alto desorden, el radix garantiza el mejor comportamiento asintótico.

#### 3. Selection Sort — O(n²)

Algoritmo de selección aplicado a pilas. En cada iteración:
1. Recorre A completo para encontrar el mínimo actual.
2. Calcula si es más corto llegar a él con `ra` (rotación hacia arriba) o `rra` (rotación hacia abajo), y aplica el camino óptimo.
3. Empuja el mínimo a B con `pb`.

Al terminar, todos los elementos están en B ordenados de mayor a menor. Se hacen `pa` sucesivos para reconstruir A en orden creciente.

**Coste típico para n=5:** ≈ 12 operaciones.

#### 4. Chunk Sort — O(n√n)

Inspirado en el algoritmo de ordenación por bloques. Pasos:
1. **Normalización de índices:** asigna a cada nodo su rango (1 = mínimo, n = máximo) sin mover la pila, en O(n²).
2. **División en chunks de tamaño √n:** procesa A en ventanas de índice `(chunk - √n, chunk]`. Para cada ventana, busca cualquier elemento de A que pertenezca al chunk actual (no importa su posición), lo rota a la cima por el camino más corto y lo empuja a B.
3. **Reconstrucción:** vacía B de mayor a menor índice hacia A, usando también rotación por camino óptimo.

**Coste típico para n=100:** ≈ 800 operaciones.

#### 5. Radix Sort — O(n log n)

Ordenación por base 2 aplicada sobre los índices normalizados. Por cada bit `i` (de menos significativo a más):
- Se recorren todos los elementos de A: si el bit `i` del índice es `0`, se empuja a B; si es `1`, se rota (`ra`).
- Una vez procesados todos, se devuelven los de B a A con `pa` sucesivos.

Tras `⌈log₂(n)⌉` pasadas, A queda ordenado por índice, que equivale al orden real de los valores.

**Coste típico para n=500:** ≈ 6 800 operaciones.

#### Optimización para tamaños pequeños

Para entradas de tamaño `5` o menor, todas las estrategias utilizan una rutina determinista optimizada para casos pequeños. Esto significa que, aunque el usuario seleccione explícitamente `--simple`, `--medium`, `--complex` o `--adaptive`, el programa comprueba primero si el stack contiene cinco elementos o menos y, en ese caso, aplica el ordenador específico para tamaños pequeños.

Esta decisión se considera un **caso base común**, no un cambio de estrategia. La flag seleccionada sigue definiendo la familia algorítmica principal usada por el programa para entradas mayores, pero aplicar `radix_sort`, ordenación por `chunks` u otra estrategia general a `2`, `3`, `4` o `5` elementos produciría operaciones innecesarias y una salida menos optimizada.

Esta lógica es habitual en implementaciones de algoritmos de ordenación: las entradas muy pequeñas se resuelven mejor mediante reglas directas y deterministas, mientras que el algoritmo general se reserva para los casos en los que sus ventajas de complejidad empiezan a ser relevantes. Para `n > 5`, la estrategia seleccionada se respeta estrictamente.

---

### 🚩 Flags opcionales (extensiones del proyecto)

El programa acepta flags antes de los números para forzar el modo o activar estadísticas:

| Flag | Efecto |
| :--- | :--- |
| `--simple` | Fuerza `selection_sort` independientemente del desorden. |
| `--medium` | Fuerza `chunk_sort`. |
| `--complex` | Fuerza `radix_sort`. |
| `--adaptive` | Modo adaptativo (comportamiento por defecto). |
| `--bench` | Imprime en `stderr` el índice de desorden, el algoritmo elegido y el desglose de operaciones. |

---

## 🛠️ Instrucciones

### Requisitos

- Compilador `cc` (gcc / clang).
- `make`.

### Compilación

```bash
# Compilar push_swap
make

# Compilar push_swap y checker (bonus)
make bonus

# Limpiar objetos
make clean

# Limpiar todo (objetos + binarios)
make fclean

# Recompilar desde cero
make re
```

### Uso

```bash
# Ordenar una lista de enteros
./push_swap 5 3 1 4 2

# Pasar los números como cadena
./push_swap "5 3 1 4 2"

# Ver estadísticas de rendimiento
./push_swap --bench 5 3 1 4 2

# Forzar un algoritmo concreto
./push_swap --complex 100 42 7 99 1
```

### Bonus — Checker

El programa `checker` lee las operaciones generadas por `push_swap` desde `stdin`, las aplica a la misma pila y verifica si el resultado está correctamente ordenado.

```bash
# Verificar que push_swap ordena correctamente
./push_swap 5 3 1 4 2 | ./checker 5 3 1 4 2
# → OK

# Pasar operaciones inválidas
echo "foo" | ./checker 5 3 1 4 2
# → Error  (en stderr)

# Pasar operaciones incompletas
echo "pb" | ./checker 5 3 1 4 2
# → KO
```

### Ejemplo completo

```bash
$ ./push_swap 5 4 3 2 1
pb
pb
ra
pb
ra
pa
pa
pa

$ ./push_swap 5 4 3 2 1 | wc -l
8

$ ./push_swap --bench --complex 5 4 3 2 1 2>&1 | grep bench
[bench] disorder: 100.00%
[bench] strategy: Complex / O(n*log(n))
[bench] total_ops: 23
```

### Pruebas con listas aleatorias grandes

Para probar con 500 números únicos se usa Python para generarlos. Es importante guardarlos en una variable para pasar **exactamente la misma lista** a `push_swap` y a `checker`:

```bash
# Generar 500 números únicos entre -1000 y 1000
ARG=$(python3 -c "import random; print(' '.join(map(str, random.sample(range(-1000,1000), 500))))")

# Ver cuántas operaciones genera
./push_swap $ARG | wc -l

# Verificar que el resultado está correctamente ordenado
./push_swap $ARG | ./checker $ARG
# → OK
```

El `checker` imprime en `stdout`:
- `OK` — las operaciones dejan A ordenada de menor a mayor y B vacía.
- `KO` — las operaciones no ordenan correctamente.
- `Error` *(en stderr)* — alguna operación generada no es válida.

#### Test de estrés

Ejecuta N pruebas seguidas y muestra si alguna falla:

```bash
for i in $(seq 50); do
    ARG=$(python3 -c "import random; print(' '.join(map(str, random.sample(range(-1000,1000), 500))))")
    RESULT=$(./push_swap $ARG | ./checker $ARG)
    echo "Test $i: $RESULT — $(./push_swap $ARG | wc -l | tr -d ' ') ops"
done
```

Salida esperada:

```
Test 1:  OK — 6743 ops
Test 2:  OK — 6891 ops
Test 3:  OK — 6654 ops
...
```

Si aparece cualquier `KO`, hay un bug en los algoritmos.

---

## 👥 Contribuciones

| Alumno | Aportaciones |
| :--- | :--- |
| **osuarez-** | Selection sort (`alg_simple.c`): diseño e implementación completa del algoritmo O(n²). Chunk sort (`alg_medium.c`): implementación principal del algoritmo por bloques O(n√n), incluyendo normalización de índices, división en chunks y reconstrucción óptima. Radix sort (`alg_complex.c`): implementación del algoritmo complejo O(n log n). Desarrollo inicial del índice de desorden (`compute_disorder`) y testeo general del programa para detectar errores de parseo, ejecución, benchmark y rendimiento. |
| **jgarcia4** | Estructura general del proyecto, parser de argumentos y flags, manejo de errores, optimización del índice de desorden (`compute_disorder`), modo adaptativo (`alg_adaptive.c`), estadísticas de benchmark (`bench.c`), checker bonus, Makefile y cabeceras. |

---

## 📚 Recursos

### Referencias

- **Radix Sort (Wikipedia):** Descripción completa del algoritmo LSD radix sort, que sirvió de base para la implementación sobre pilas.
- **Counting Inversions (GeeksforGeeks):** Explicación del cálculo del número de inversiones en un array, aplicado aquí como índice de desorden.


### Uso de Inteligencia Artificial

Siguiendo las directrices del subject, se ha utilizado IA generativa (Claude) como herramienta de apoyo al desarrollo:

- **Detección y corrección de bugs:** Identificación de casos de error no contemplados en el parseo de flags (flags duplicadas, flags sin números), errores de índice en `index_sort` y variables sin inicializar.
- **Revisión de norma:** Detección de violaciones de la norma de 42 (funciones de más de 25 líneas, más de 5 funciones por archivo, errores de indentación), con propuesta de refactorizaciones que respetan los límites.
- **Estructura del proyecto:** Sugerencia de la separación en carpetas `utils/` y `bonus/`, y simplificación del Makefile mediante static pattern rules.
- **Implementación del checker bonus:** Diseño de la lectura de operaciones desde `stdin` y la aplicación silenciosa de las mismas sobre las pilas.

La lógica algorítmica (selection sort, chunk sort, radix sort, índice de desorden y modo adaptativo) ha sido diseñada e implementada manualmente por el equipo.
