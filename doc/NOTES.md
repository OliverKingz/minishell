# NOTES

## LEYENDA:
- ✅ It works, maybe with frees and leaks
- ❌ Wrong
- ⌛ Work in Progress
- 🆓 There are leaks to fix. Waiting for parse.
- ❓ No se si tiene que contemplarse

## EXAMPLE EXPANSION
```
export VAR1="echo hola mundo |          cat -e"
```
`$VAR1` se expande a:
```
char *s="echo" "hola" "mundo" "|"          "cat" "-e"
```

---

## HISTORIAL
- Revisar que no hay fugas acumulados, cuando está lleno. Da leaks. Usar fsanitize.

---

## LEAKS
- Mirar cuando el comando da error, y cortas con señales, hay que liberar también.

---

## CASOS A CONSULTAR
- `echo 'Hello/nWorld' | \\\n` ❓
- Deberiamos usar \n y \t❓

## CASOS DONDE FALLA
- "ech"o ⌛
- ec""ho ⌛

---

# FINISHED ✅

## TESTS
- echo hola | <<EOF cat -e ✅
- find . -type f -name "*.c" | xargs grep "main" > results.txt ✅

## TOKENIZACION
- Pipes entre `""` y `''` los toma como texto. ✅
- Sin mandatory: `cat||cat` lo interpretaría como `cat '||' cat` o `cat | | cat`. ✅
- Para `;`, `\`, mejor ni siquiera mirarlo al principio (incluido `#`, `=`, `)`). ✅
- `||` tratarlo. ✅
- `""` y `''` tratarlo como syntax error si no está cerrado. ✅
- Taggear: orden de prioridad✅
  - Si es pipe, si es redirección doble, redirección simple.✅
  - Luego comando/argumento al mismo nivel (si ya he puesto un comando antes, este será argumento).✅
- Comandos que terminan en `>`, `>>`, `<`, `<<` y `|`✅
Todos son errores de sintaxis, mirar explicación Slack/DM. ✅

## SEÑALES
- Si pones algo, y usas CTRL+D no hace exit, solo si está esperando.✅

## COMANDOS VÁLIDOS E INVÁLIDOS
- cat < in | grep "Hi bye" | grep 'M' > out | cat >> final_out -e ✅
- Cambia count_cmds_heredocs a single puntero, solo lees. Recuerda explicación. ✅
- Solo importa las comillas exteriores, expansión ✅
  - echo '$USER' ✅
    $USER
  - echo "'$USER'" ✅
    'raperez-'
  - echo "hola '  " ✅
  - echo "$USER" '$USER' "'$USER" '$USER"' $USER ✅
  - cat | | cat (make validate_tokens_syntax) ✅

### Comandos Inválidos ✅
- echo hola | | cat -e
- echo hola > | cat -e
- echo hola > > cat -e
- echo hola > < cat -e
- echo hola > << cat -e
- echo hola < | cat -e
- echo hola < > cat -e
- echo hola < < cat -e
- echo hola < << cat -e
- echo hola >> | cat -e
- echo hola >> > cat -e
- echo hola >> < cat -e
- echo hola >> << cat -e
- echo hola << | cat -e
- echo hola << < cat -e
- echo hola << << cat -e
- echo hola > >> cat -e
- echo hola < >> cat -e
- echo hola < << cat -e
- echo hola >> >> cat -e
- echo hola >> << cat -e
- echo hola << > cat -e

### Comandos Válidos ✅
- echo hola | > cat -e
- echo hola | < cat -e
- echo hola | >> cat -e
- echo hola | << cat -e

---

## TOKENIZACIÓN
- Dentro de los tokens, quitar las comillas exteriores. Investigar más. ✅
- Casos donde tiene que funcionar:
  - ""echo ✅
  - echo"" ✅
  - ""echo"" ✅
  - "" echo "" ✅
  - "echo" 'que' ""tal"" ''yo'' ✅
    [echo     ]→[que      ]→[tal      ]→[yo       ]
    [COMMAND  ]→[ARG      ]→[ARG      ]→[ARG      ]
  - "ech"o ⌛
  - ec""ho ⌛

---

# TO DO INMEDIATO OLIVER
- Organizar var_expansions.
- Cambiar mi libft para poner ft_calloc bien.
- No separar los `""`:
  - "ec"ho funciona el comando.
- IDEA: Quitar los `""` y `''` después de tokenizar.

---

# TO DO LEJANO OLIVER
- Minishell tiene que detectar en qué minishell está para poder matar a la buena. Tenerlo dentro de la estructura.
  - Incluso si lo mato en otra ventana.
- Poner loop en un fork???

---

# TO DO/PREGUNTAR/DECIR A RAUL
- Mirar env de emergencia y PATH de emergencia.
- Mirar qué pasa cuando init devuelve NULL.
- En los init con muchos calloc, siempre checkeo. ¿Qué opinas de juntarlos todos en 1?
- Revisar validate_tokens_syntax, muchos casos.

---