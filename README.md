# Cifra de César em C

Programa de terminal que cifra e decifra textos usando a Cifra de César, feito como trabalho escolar.

## Funcionalidades

1. **Cifrar**: desloca cada letra do texto pelo valor informado.
2. **Decifrar**: desfaz o deslocamento.
3. **Força bruta**: mostra o texto decifrado com todos os deslocamentos de 1 a 25, útil quando não se conhece a chave.

Maiúsculas e minúsculas são preservadas; números, espaços e símbolos não mudam. Deslocamentos negativos ou maiores que 26 também funcionam.

## Como compilar e executar

```bash
make
./cifra_cesar
```

Ou, sem o `make`:

```bash
gcc -o cifra_cesar cifra_cesar.c
./cifra_cesar
```

## Exemplo

Texto: `Ola Mundo`, deslocamento: `3` → `Rod Pxqgr`

## Observações

- Funciona em Linux, macOS e Windows (a limpeza de tela usa `clear` ou `cls` conforme o sistema).
- Letras acentuadas não são cifradas, apenas as letras de A a Z.
