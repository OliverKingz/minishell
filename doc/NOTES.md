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
- Guardar el historial no es obligatorio. 

---

## LEAKS
- Mirar cuando el comando da error, y cortas con señales, hay que liberar también.

---

# DUDAS RESUELTAS
- En los init con muchos calloc, siempre checkeo. ¿Qué opinas de juntarlos todos en 1?

---

# TERMINADO ✅

## TESTS
```C
cat < in | grep "Hi bye" | grep 'M' > out | cat >> final_out -e✅
echo hola | <<EOF cat -e ✅
find . -type f -name "*.c" | xargs grep "main" > results.txt ✅
```

## TOKENIZACION
- Sin mandatory: `cat||cat` lo interpretaría como `cat '||' cat` o `cat | | cat`. ✅
- Para `;`, `\`, mejor ni siquiera mirarlo al principio (incluido `#`, `=`, `)`). ✅
- Taggear: orden de prioridad✅
  - Si es pipe, si es redirección doble, redirección simple.✅
  - Luego comando/argumento al mismo nivel (si ya he puesto un comando antes, este será argumento).✅
- Comandos que terminan en `>`, `>>`, `<`, `<<` y `|`✅
Todos son errores de sintaxis, mirar explicación Slack/DM. ✅

### HANDLE QUOTES
- Pipes entre `""` y `''` los toma como texto. ✅
- `""` y `''` tratarlo como syntax error si no está cerrado. ✅
- Dentro de los tokens, quitar las comillas exteriores. Investigar más. ✅
- Casos donde tiene que funcionar:
```C
  ""echo ✅
  echo"" ✅
  ""echo"" ✅
  "" echo "" ✅
  "echo" 'que' ""tal"" ''yo'' ✅
  "ech"o ⌛ 
  ec""ho ⌛
  "" -> Esto es token valido. Yo no lo tokenizo.⌛
```
  "echo" 'que' ""tal"" ''yo'' ✅
    [echo     ]→[que      ]→[tal      ]→[yo       ]
    [COMMAND  ]→[ARG      ]→[ARG      ]→[ARG      ]

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
```C
echo hola | | cat -e
echo hola > | cat -e
echo hola > > cat -e
echo hola > < cat -e
echo hola > << cat -e
echo hola < | cat -e
echo hola < > cat -e
echo hola < < cat -e
echo hola < << cat -e
echo hola >> | cat -e
echo hola >> > cat -e
echo hola >> < cat -e
echo hola >> << cat -e
echo hola << | cat -e
echo hola << < cat -e
echo hola << << cat -e
echo hola > >> cat -e
echo hola < >> cat -e
echo hola < << cat -e
echo hola >> >> cat -e
echo hola >> << cat -e
echo hola << > cat -e
```

### Comandos Válidos ✅
```C
echo hola | > cat -e
echo hola | < cat -e
echo hola | >> cat -e
echo hola | << cat -e
```

---

## CASOS A CONSULTAR
- `echo 'Hello/nWorld' | \\\n` Deberiamos usar \n y \t -> Manejarlo

## CASOS DONDE FALLA
- "ech"o ⌛ 
- ec""ho ⌛
- ""

- No separar los `""`:
  - "ec"ho funciona el comando.
  - IDEA: Quitar los `""` y `''` después de tokenizar.
  - IDEA: Usar my_replace(?) Donde usarlo? antes del handle?
		if (!my_replace(current->content, "\"", ""))
			return (my_perr("remove_quotes", true, errno), false);
  - Concatenation of characters: This ensures that characters inside quotes are concatenated and treated as single tokens.


# TO DO INMEDIATO OLIVER
- Hacer signal.c
  - signal(SIGINT, handle_ctrl_c);
  - Investigar para que vale señal global
  - signal(SIGQUIT, handle_ctrl_backslash)
    -	signal(SIGQUIT, SIG_IGN);

- History file (no es obligatorio)
  - Create with open, append. 
  - Como pongo limite? 


# TO DO LEJANO OLIVER
- Minishell tiene que detectar en qué minishell está para poder matar a la buena. Tenerlo dentro de la estructura.
  - Incluso si lo mato en otra ventana.
- Poner loop en un fork???

---

# TO DO/PREGUNTAR/DECIR A RAUL
- Mirar env de emergencia y PATH de emergencia.
- Mirar qué pasa cuando init_envlist devuelve NULL.
- En los init con muchos calloc, siempre checkeo. ¿Qué opinas de juntarlos todos en 1? -> Solo si hace falta espacio
- Revisar validate_tokens_syntax, muchos casos.
- Hacer $?
- Integrar ejecución, haciendo los archivos ya con 5 funciones, y bien nombrados.

# RAUL

---