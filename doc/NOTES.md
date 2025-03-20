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
  -> Solo si hace falta espacio
- Revisar validate_tokens_syntax, muchos casos.
  -> Todos bien


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
  "ech"o ✅
  ec""ho ✅
  "echo "✅
  "" ✅
  ""ec"""h"o"" ✅
  ""ec"""ho" ✅
  "echo" 'que' ""tal"" ''yo'' ✅
```
  "echo" 'que' ""tal"" ''yo'' ✅
    [echo     ]→[que      ]→[tal      ]→[yo       ]
    [COMMAND  ]→[ARG      ]→[ARG      ]→[ARG      ]

## SEÑALES
- Si pones algo, y usas CTRL+D no hace exit, solo si está esperando.✅
- Hacer signal.c ✅
  - signal(SIGINT, handle_ctrl_c); ✅
  - Investigar para que vale señal global ✅
  - signal(SIGQUIT, handle_ctrl_backslash) ✅
    -	signal(SIGQUIT, SIG_IGN);

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
- echo 12e > /dev/full
bash: echo: write error: No space left on device

## CASOS DONDE FALLA
- Hacer Ctrl+C con un comando como cat: Se duplica el prompt (Bug visual que no se ve :D)

# TO DO INMEDIATO OLIVER
- Hacer builtins echo y exit ✅
- Investigar el return de echo. Siempre 0? Como se falla. ✅
    -> Opciones incorrectas las representa igual ✅
- Exit tiene que tener si o si solo 1. Poner exit: too many arguments✅
- Enum de builtin. ✅
- Hacer funcion si es builtin o no. ✅

- Ver CTRL+\ mejor✅
- Exit
  - caso: exit 1 2 3 4, no sale✅
  - caso: exit brenda 2 3 4, si sale✅
  - caso: exit brenda✅
  - caso: ls | exit 12✅ si sale, pero el hijo
- Export
  - Preguntar export, si es igual que env pero poniendo declare -x, ordenando la lista y poniendo el value entre comillas ""✅
  - export 0a a b= c="" d="ho""la" e?✅
  - Preguntar si poner deckare -x. @tischmid en Slack pone que no
  - Necesario ordenar? Para eso necesito duplicar primero y luego ordenar el rep. Saber como esta ordenado env as well
- Unset
  - No falla nunca, solo con casos readonly (Que no hace falta)
- Pwd
- Cd

- Revisar bi por casos flags multiples. Mirar solo si el char es una flag uno a uno. 
- Fix export ''
- Hacer SHLVL en create_shell

# TO DO LEJANO OLIVER
- Minishell tiene que detectar en qué minishell está para poder matar a la buena. Tenerlo dentro de la estructura.
  - Incluso si lo mato en otra ventana.
- Poner loop en un fork???

- History file (no es obligatorio)
  - Create with open, append. 
  - Como pongo limite? 
---

# TO DO/PREGUNTAR/DECIR A RAUL
- Mirar qué pasa cuando init_envlist devuelve NULL.
  -> 
- Getenv
- Heredoc
- Chequear que tan probables es que falle dup/dup2
- perror o personal err 

# SLACK

# DONE RAUL
- Hacer $? ✅
- Integrar ejecución, haciendo los archivos ya con 5 funciones, y bien nombrados.✅
- Quitar replace all?✅
- Mirar env de emergencia y PATH de emergencia.✅
  -> No hacerlo. No lo hacen todas las shells, y tiene haters xq hardcodea el PATH
- Segun vbengea, no hay hacer en hdoc <<'eof'✅
  -> Tiene razon. Por el subject no lo menciona. 
- Preguntar si poner declare -x. @tischmid en Slack pone que no, que lo tiraria✅
  -> Lo hemos quitado. No queremos programar declare. 


---