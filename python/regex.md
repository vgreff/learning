

https://stackoverflow.com/questions/2637592/perl-like-regex-in-python

import re

myre = re.compile(r'(.*?):([^-]*)-(.*)')
for line in lines:
    mo = myre.search(line)
    field_1, field_2, field_3 = mo.groups()


m = re.search(r'(.*?):([^-]*)-(.*)', line)
field_1 = m.group(1)
field_2 = m.group(2)
field_3 = m.group(3)


import re
p = re.compile(r'(\d+)\.(\d+)')
num_parts = p.findall('11.22   333.444') # List of tuples.
print num_parts                          # [('11', '22'), ('333', '444')]

https://lzone.de/examples/Python%20re.sub

result = re.sub("(\d+) (\w+)", r"\2 \1")
