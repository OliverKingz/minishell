# ENUM TYPES

- Hemos quitado `option`, ya que es un argumento, y `Var`, ya que expandimos todos los `$` antes de tokenizar.
- Si el `|` está entre comillas, considerarlo como argumento.
- Si `|`, `<`, `<<`, `>`, `>>` están entre comillas, no tomarlos como caracteres especiales.

## Example

### Input Line
```
cat < in | grep "Hola    Mundo" | grep 'M' > out | cat >> final_out -e
```

### Tokenizer Result
```
"cat" "<" "in" "|" "grep" ""Hola    Mundo"" "|" "grep" "'M'" ">" "out" "|" "cat" ">>" "final_out" "-e"
```

### Token Classification
- `"cat"`: command
- `"<"`: redir_in
- `"in"`: file_path
- `"|"`: op_pipe
- `"grep"`: command
- `""Hola    Mundo""`: argument
- `"|"`: op_pipe
- `"grep"`: command
- `"'M'"`: argument
- `">"`: redir_out
- `"out"`: file_path
- `"|"`: op_pipe
- `"cat"`: command
- `">>"`: redir_append
- `"final_out"`: file_path
- `"-e"`: argument

## Example Expansion
```
export VAR1="echo hola mundo |          cat -e"
```
`$VAR1` se expande a:
```
char *s="echo" "hola" "mundo" "|"          "cat" "-e"
```

## Example: Terminar con `>`, `>>`, `<`, `<<` y `|`
```
ls |
```
Todos son errores de sintaxis, mirar explicación Slack/DM.

## Additional Notes
- `echo 'Hello/nWorld' | \\\n`
- Pipes entre `""` y `''` los toma como texto.
- Sin mandatory: `cat||cat` lo interpretaría como `cat '||' cat` o `cat | | cat`.

- `echo 'Hello/nWorld' | \\\n`
- Pipes entre `""` y `''` los toma como texto.
- Sin mandatory: `cat||cat` lo interpretaría como `cat '||' cat` o `cat | | cat`.

- Para `;`, `\`, mejor ni siquiera mirarlo al principio (incluido `#`, `=`, `)`).
- `||` tratarlo.
- `""` y `''` tratarlo como syntax error si no está cerrado.

- Taggear: Orden de prioridad (en el orden de mirar ifs al tagear):
  - Si es pipe, si es redirección doble, redirección simple.
  - Luego comando/argumento al mismo nivel (si ya he puesto un comando antes, este será argumento).


## Historial
- Revisar que no hay fugas acumulados, cuando esta lleno. Da leaks. Usar fsanitize. 

## Leaks
- Mirar cuando el comando da error, y cortas con señales, hay que liberar tambien. 

## Señales
- Si pones algo, y usas CTRL+D no hace exit, solo si esta esperando

---