#!/usr/bin/env sh

root=$(dirname $0)
server="$root/server"
client="$root/client"

randint() {
    od -vAn -N1 -tu4 < /dev/urandom | bc
}

"$server" | sed '1,2d' > "$root/server.log" &
server_pid=$(jobs -p)

rm -f client.log
for i in $(seq 1 $1); do
    line="$(openssl rand -base64 $(randint))"
    "$client" $server_pid "$line" > /dev/null
    echo "$line" >> "$root/client.log"
done

kill $server_pid
if diff "$root/client.log" "$root/server.log" > /dev/null 2>&1; then
    printf -- "\033[32mOK"
else
    printf -- "\033[31mKO"
fi
printf -- "\033[0m\n"
