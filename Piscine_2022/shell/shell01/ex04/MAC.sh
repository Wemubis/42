#!/bin/sh
ifconfig -a | grep -w ether | sed 's/.ether //' | tr -d ' '
