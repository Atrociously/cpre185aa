FIRST_NAME := "Jack"
LAST_NAME := "Morrison"

# list the available commands
list:
    just --list

alias begin := start
alias submit := prepare

# start a new c submission. copies the template to a new file
start filename:
    #!/usr/bin/env bash

    set -euo pipefail

    cp "{{justfile_directory()}}/template.c" "{{filename}}"

# run the specified c file by first compiling it with gcc
run buildfile *args:
    #!/usr/bin/env bash

    set -euo pipefail

    mkdir -p "{{justfile_directory()}}/target"
    OUTNAME=$(basename {{buildfile}} .c)
    gcc -o "{{justfile_directory()}}/target/${OUTNAME}" "{{buildfile}}"
    sh -c "{{justfile_directory()}}/target/${OUTNAME}" {{args}}

# prepare the specified file for submission by filling in important details
prepare buildfile *args:
    #!/usr/bin/env bash

    set -euo pipefail

    OUTDIR="{{justfile_directory()}}/submissions"

    echo -n "Enter day number: "
    read daynum

    OUTDIR="{{justfile_directory()}}/submissions/day${daynum}"
    mkdir -p "${OUTDIR}"

    echo -n "Enter title: "
    read title
    echo "What were you trying to learn or achieve?"
    read reflection1_answer
    echo "Were you successful? Why or Why not?"
    read reflection2_answer
    echo "Would you do anything differently if starting this program over? If so, explain."
    read reflection3_answer
    echo "Think about the most important thing you learned when writing this piece of code."
    echo "What was it and explain why it was significant."
    read reflection4_answer

    OUTPATH="${OUTDIR}/{{LAST_NAME}}_{{FIRST_NAME}}_AA_Day${daynum}.c"
    cp "{{buildfile}}" "${OUTPATH}"
    
    sed -i -e "s/={DAYNUM}/${daynum}/" \
        -e "s/={TITLE}/${title}/" \
        -e "s/={ANSWER_1}/${reflection1_answer}/" \
        -e "s/={ANSWER_2}/${reflection2_answer}/" \
        -e "s/={ANSWER_3}/${reflection3_answer}/" \
        -e "s/={ANSWER_4}/${reflection4_answer}/" \
        "${OUTPATH}"

    echo "Running ${OUTPATH}"
    echo ""
    just run "${OUTPATH}" {{args}}

    sleep 0.1
    # take a screenshot then use the custom python docxwriter to convert it to a docx for submission
    IMAGEPATH="${OUTDIR}/{{LAST_NAME}}_{{FIRST_NAME}}_AAOutput_Day${daynum}.png"
    maim -i "$(xdotool getactivewindow)" "${IMAGEPATH}"
    {{justfile_directory()}}/docxwriter/venv/bin/python "{{justfile_directory()}}/docxwriter/saveimage.py" "${IMAGEPATH}"
    rm ${IMAGEPATH}
