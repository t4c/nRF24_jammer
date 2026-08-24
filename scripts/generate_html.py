import os
import glob

Import("env")

def generate_html_header():
    project_dir = env.get("PROJECT_DIR")
    pio_env = env.get("PIOENV")
    html_dir = os.path.join(project_dir, "html")
    output_header = os.path.join(project_dir, "include", pio_env, "html.h")

    if not os.path.exists(html_dir):
        print(f"Warning: '{html_dir}' directory not found.")
        return

    header_content = "#ifndef HTML_H\n#define HTML_H\n\n"

    html_files = sorted(glob.glob(os.path.join(html_dir, "*.html")))
    
    for file_path in html_files:
        filename = os.path.basename(file_path)
        var_name = os.path.splitext(filename)[0]

        with open(file_path, "r", encoding="utf-8") as f:
            content = f.read()

        header_content += f'static const char *const {var_name} = R"rawliteral(\n{content}\n)rawliteral";\n\n'

    header_content += "#endif\n"

    if os.path.exists(output_header):
        with open(output_header, "r", encoding="utf-8") as f:
            if f.read() == header_content:
                return

    os.makedirs(os.path.dirname(output_header), exist_ok=True)
    with open(output_header, "w", encoding="utf-8") as f:
        f.write(header_content)
        print(f"Successfully generated: {output_header}")

generate_html_header()