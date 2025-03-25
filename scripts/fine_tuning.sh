# **************************************************************************** #
#                    no arreglar M (MANDATORORY)                               #
# **************************************************************************** #

# **************************************************************************** #
#                    no arreglar NE (SIN ENV)                                  #
# **************************************************************************** #

# /bin/cat Makefile > out >>out1 >out2 | /bin/cat << stop > out3 | /bin/ls > > | /bin/cat << file
# will make you cry
# stop
# /bin/rm -rf out
# /bin/rm -rf out1
# /bin/rm -rf out2
# /bin/rm -rf out3
# cd ..
# pwd

/bin/cat Makefile > out >>out1 >out2 | /bin/cat << stop > out3 | /bin/ls
testinator
stop
/bin/rm -rf out
/bin/rm -rf out1
/bin/rm -rf out2
/bin/rm -rf out3

# unset PATH
# cat
# cd ..
# exit

# unset PATH
# pwd
# cd -
# pwd
# exit

# unset PATH
# pwd
# cd ~
# pwd

# unset PATH
# pwd
# cd ~
# pwd
# cd -
# pwd

# cd
# cd ~

# unset PATH
# env

# env

# export

# exit asd

# exit 5

# exit 5 asd

# **************************************************************************** #
#                    no arreglar D (PIPE SEGFAULT TEST BRUTAL)                 #
# **************************************************************************** #

# echo segf >| echo is this invalid

# echo <<< echo seegf

# echo seg <> echo seg

# echo test |  <<lala

# echo segfault < " < < < " < < amazing
# .
# amazing

# echo segfault <"    <   <   <"  <   <   amazing
# .
# amazing

# **************************************************************************** #
#                                CLASIFICAR ERRORES                            #
# **************************************************************************** #

touch tmp_x_file1
tmp_x_file1
echo $?
./tmp_x_file1
echo $?
export PATH=$HOME
echo $PATH
tmp_x_file1
echo $?
./tmp_x_file1
echo $?
unset PATH
tmp_x_file1
echo $?
./tmp_x_file1
echo $?
echo 42
/bin/rm -f tmp_x_file1

cat << 'lim'
$USER
$NOVAR
$HOME
lim

cat << lim''
$USER
$NOVAR
$HOME
lim

cat << "lim"
$USER
$NOVAR
$HOME
lim

cat << 'lim'
$USER
$NOVAR
$HOME
lim

ls | cat << stop | ls -la | cat << stop1 | ls | cat << stop2 | ls -la > out | cat << 'stop3'
$USER
ad
stop
dsa
stop1
sad
stop2
as $HOME
stop3
/bin/rm -f out

# **************************************************************************** #
#                               FALTA ARREGLAR                                 #
# **************************************************************************** #

cat << $USER
why
not
$USER

cat << "$USER"
why
not
$USER

cat << "$US"E"R"
because
we
love
bash
$USER

# **************************************************************************** #
#                                    ARREGLADO                                 #
# **************************************************************************** #

| echo -n oui

| test

|ls | ls

export PATH=""
ls

./ls

"./"ls

"./""ls"

"./"''"ls"

/

/bin/

# **************************************************************************** #
#                                NO ARREGLAR                                   #
# **************************************************************************** #

# RAZON: no manejamos argumentos con env, -i es opcion y tampoco manejamos args
# echo "env | /usr/bin/wc -l" | env -i $MINISHELL_PATH"/"$EXECUTABLE
# echo $?

# echo "ls" | env -i $MINISHELL_PATH"/"$EXECUTABLE
# echo $?

# echo "unset PATH" | env -i $MINISHELL_PATH"/"$EXECUTABLE
# echo $?

# env -i ./minishell
# cd /bin/
# ls

# env -i ./minishell
# cd /bin/
# /usr/bin/ls

# RAZON: no es La operación += se considera una forma de manipulación o modificación 
# del valor durante la exportación, lo que técnicamente podría interpretarse como una
# "opción" o una funcionalidad adicional más allá de la simple exportación.
# export TEST+=100

# RAZON: subject no especifica, haria solo cd a HOME, -- no es una ubicacion
# cd --
