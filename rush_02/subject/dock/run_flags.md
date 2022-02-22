
## Docker run Flags

### Run command

All in one :
`docker run --cpus="1" --memory="128m" --kernel-memory="192m" --memory-swap="192m" --network none`

These flags will be used for our tests.
It's ***highly recommended*** to use them for testing.

### List of used flags

`--cpus=<value>`
- Limit the specific CPUs or cores a container can use.

`-m | --memory`
- The maximum amount of memory the container can use.

`--kernel-memory`
- For the kernel memory.
- More than --memory : "If the kernel memory limit is higher than the user memory limit, the kernel limit does not cause the container to experience an OOM."

`--memory-swap`
- Amount of memory that can be swapped on disk
- default = 128mo

`--network`
- `none` to disable networking (all types)  : `--network none`
