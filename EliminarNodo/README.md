
# Eliminación de Nodos en un Árbol Binario de Búsqueda (ABB)

Este documento explica paso a paso cómo eliminar un nodo en un Árbol Binario de Búsqueda (ABB), considerando los tres casos clásicos. Se incluyen ejemplos gráficos en ASCII para una mejor comprensión.

---

## ✅ CASO 1: El nodo a eliminar **no tiene hijos** (nodo hoja)

### Pasos:
1. Buscar el nodo a eliminar y su padre.
2. Verificar si es hijo izquierdo o derecho.
3. Asignar `NULL` al puntero correspondiente en el padre.
4. Liberar la memoria del nodo eliminado.

### Ejemplo:

```
Antes:        Después:

     40           40
    /  \         /  \
   20  60       20  60
         \
         70
```

Eliminar el nodo `70` (hoja).

---

## ✅ CASO 2: El nodo a eliminar **tiene un solo hijo**

### Pasos:
1. Buscar el nodo a eliminar y su padre.
2. Reemplazar el puntero del padre por el único hijo del nodo.
3. Liberar el nodo eliminado.

### Ejemplo:

```
Antes:        Después:

     40           40
    /  \         /  \
   20  60       20  60
         \            \
         70           80
```

Eliminar `70`, que tiene un solo hijo derecho `80`.

---

## ✅ CASO 3: El nodo a eliminar **tiene dos hijos**

### Pasos:
1. Buscar el sucesor in-order (menor del subárbol derecho).
2. Copiar el valor del sucesor al nodo a eliminar.
3. Eliminar el sucesor, que será caso 1 o 2.

### Ejemplo:

```
Antes:                       Después:

     50                            60
    /  \                          /  \
  30    70        =>            30    70
       /                            \
     60                              80
       \
       80
```

Se elimina `50`, reemplazado por su sucesor `60`. Luego `60` se elimina (caso 2).

---

## 🎯 ¿Y si los nodos son complejos?

Si los nodos tienen mucha información (nombre, dirección, etc.), es mejor **mover punteros** en lugar de copiar datos. Esto mantiene consistencia y eficiencia.

### ¿Cómo?
- Se encuentra el sucesor.
- Se enlazan los hijos del nodo a eliminar al sucesor.
- Se reemplaza el puntero en el padre.

---

## 🧠 Ventajas de mover punteros

- Evita duplicar datos pesados.
- Conserva referencias válidas.
- Más rápido y limpio.

---

## 🔚 Conclusión

Eliminar un nodo de un ABB requiere analizar sus hijos. Aplicar la estrategia correcta garantiza que el árbol siga siendo válido.

