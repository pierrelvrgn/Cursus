
#######################################################
### Be carefull
#
# This Dockerfile meant to stay in the same directory as
# the same folder where it came from (the downloaded
# repository).
#
# If you want to keep most of the stuff intact in this
# Dockerfile, keep the same architecture (folder's name,
# folder's place).
#
# But, you are free and enjoin modify this Dockerfile,
# or even make your own. (just keep the mandatory parts
# gave by the subject).
#
# This Dockerfile has only the purpose to help you make
# your own build, so keep it in mind.
#
# Refere to the subject to identify which parts are
# mandatory in this Dockerfile.
#
# Don't forget to check the Docker's Manual if you have 
# any question :
# https://docs.docker.com/engine/reference/builder/
#
# For the multi-stage build :
# https://docs.docker.com/develop/develop-images/multistage-build/

#######################################################
### Builder stage
#
# Everything need to be built here.
#
# The builder stage must contain everything you need
# but don't want to see in the final image or conainter.
#
# Example : your compilation requirements.
#
FROM debian:10 as builder

## Compilation stage :
#
# If you have a language which need a compilation phase
# (C, C++, Go, Rust), compile it here in the
# 'builder stage'.
# Launching `update` command before is a good practice 
# and in some cases necessary if you want to install
# or update some packages. (`apt` is the package manager
# of Debian)
#
RUN apt update && apt install -y [your needs]

## Mandatory copy and workdir
#
WORKDIR /build

COPY . .

## Building commands :
#
# The bots are built here.
# Add your own if you need it.
#
RUN [building commands]


#######################################################
### Runner stage
#
# Everything you need to run your program
#
# The less the better : it must at least only run a
# binary. 
# Example : If you need Python to make your
# Python code works, intall it and use CMD to do it.

FROM debian:10-slim

# Mandatory user, copy and workdir presets :
#
WORKDIR /app

RUN adduser player && chown -R player /app

USER player

COPY --from=builder /build/* /app/player

## Setup phase
#
# Setup here everything you need to make your 'player' works.
#
RUN apt update && apt install -y [your needs] \
	&& [running commands]

## Launching phase
#
# You SHOULD launch your program at the start of
# the container. Our program will only these :
# `docker build` and then `docker run`.
#
# You've been warned !
#
CMD ./player

