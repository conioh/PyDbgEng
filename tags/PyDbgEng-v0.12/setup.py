
# Dirty setup for PyDbgEng

from distutils.core import setup
setup(name='PyDbgEng',
	  author='Botten Biss, Michael Eddington',
	  author_email='mike@phed.org',
	  url='http://phed.org',
	  version='0.12',
	  packages=['PyDbgEng'],
	  package_data={'PyDbgEng': ['data/*']},
	  )