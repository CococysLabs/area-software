# [773] Manejo e Implementación de Archivos
## 📁 Contenido

Cada ciclo contiene el material del curso organizado según la estructura original del profesor/catedrático.

## 📥 Clonar

Esta sección es únicamente para descargar el contenido del repositorio de forma más fácil, sin necesidad de traer todos los cursos y ciclos completos.

### Descargar un curso y un ciclo específico

Para descargar solamente un ciclo específico de un curso, usa:

```bash
git clone --filter=blob:none --sparse https://github.com/CococysLabs/area-software.git nombre-carpeta
cd nombre-carpeta
git sparse-checkout set curso/ciclo-xxxx-xxxx-xxxx
```

Donde:

- `nombre-carpeta` es el nombre que tendrá la carpeta descargada en tu computadora.
- `curso` es la carpeta del curso que deseas descargar.
- `ciclo-xxxx-xxxx-xxxx` es el ciclo específico que deseas descargar.

### Descargar todos los ciclos de un curso

Para descargar todos los ciclos de un curso, usa:

```bash
git clone --filter=blob:none --sparse https://github.com/CococysLabs/area-software.git nombre-carpeta
cd nombre-carpeta
git sparse-checkout set curso
```

Donde:

- `nombre-carpeta` es el nombre que tendrá la carpeta descargada en tu computadora.
- `curso` es la carpeta del curso que deseas descargar.

## 🤝 Contribuir

Si deseas contribuir con material para este curso:

1. Fork el repositorio [area-software](https://github.com/CococysLabs/area-software)
2. Crea una rama: `git checkout -b feature/773-add-content`
3. Agrega tu contenido en el ciclo correspondiente
4. Commit: `git commit -m "feat(773): agregar [descripción]"`
5. Push y crea un Pull Request

## 📧 Contacto

- Email: cococys@ingenieria.usac.edu.gt
- Organización: [CococysLabs](https://github.com/CococysLabs)

---

**Ruta:** [Área de Software](../) → [773] Manejo e Implementación de Archivos
