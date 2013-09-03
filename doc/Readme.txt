Converting ReST to Sphinx(html)

Sphinx is a tool that makes it easy to create intelligent and beautiful documentation.Sphinx uses reStructuredText as its markup language, and many of its strengths come from the power and straightforwardness of reStructuredText and its parsing and translating suite, the Docutils.

To install sphinx run the following command in terminal

$ sudo apt-get install python-sphinx 

or

$ pip install sphinx

Steps to follow :

To start generating html from rst run this in terminal

$ sphinx-quickstart

Accept all default questions by hitting enter key for a default build.

Read the questions if you want anything other than default.

Now open anuduino.rst and add your ReST file names (without extension), and with proper indentation. Assuming all ReST files in present working directory.

Now, simply do 

make html

Now go to _build/html directory and open anuduino.html in web browser.


