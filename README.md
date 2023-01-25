CprE 185 Class Activites
========================
This repo contains all my code for cpre185 in class activities.
In here there is a `Justfile` which contains scripts for automating
some of the process. To start a new in class activity run `just start <filename>`
where you replace `<filename>` with the name of the file you want to create.
Then to run the code you can use `just run <filename> [args]`, replace the filename
again and optionally any arguments that you want to pass to the executable.
When you are ready to submit the code run `just prepare <filename>` and it will
walk you through the required information to finalize everything and take a screenshot
of your active window after running the code.
