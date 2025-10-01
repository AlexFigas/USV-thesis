#!/bin/bash

MAIN="TFM"

echo "=== 1. LaTeX (primeira compilação) ==="
pdflatex -synctex=1 -interaction=nonstopmode -file-line-error "$MAIN.tex"

echo "=== 2. BibTeX ==="
bibtex "$MAIN"

echo "=== 3. Glossaries ==="
makeglossaries "$MAIN"

echo "=== 4. LaTeX (segunda compilação) ==="
pdflatex -synctex=1 -interaction=nonstopmode -file-line-error "$MAIN.tex"

echo "=== 5. LaTeX (terceira compilação) ==="
pdflatex -synctex=1 -interaction=nonstopmode -file-line-error "$MAIN.tex"

echo "✅ Build completo: $MAIN.pdf"
