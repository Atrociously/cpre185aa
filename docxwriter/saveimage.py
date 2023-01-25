import sys
from docx import Document
from docx.shared import Inches

def main():
    if len(sys.argv) < 2:
        print("Please specify an input image")
        return;

    input_image = sys.argv[1];
    outfile = input_image.rsplit(".", 1)[0] + ".docx"

    doc = Document()
    doc.add_picture(input_image, width=Inches(6))
    doc.save(outfile)


if __name__ == "__main__":
    main()
