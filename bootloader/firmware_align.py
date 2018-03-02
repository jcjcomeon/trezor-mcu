#!/usr/bin/env python
import sys
import os

fn = sys.argv[1]
fs = os.stat(fn).st_size
if fs > 34816:
	print(fs)
	raise Exception(fs)
	raise Exception('bootloader has to be smaller than 32768 bytes')
#with open(fn, 'ab') as f:
#	f.write(b'\xFF' * (34816 - fs))
#	f.close()
