# 二进制资源转 C++ 头文件。

from pathlib import Path
import sys


def BuildIdentifier(Value):
    Result = []
    for Char in Value:
        if Char.isalnum():
            Result.append(Char)
        else:
            Result.append("_")

    Text = "".join(Result).strip("_")
    if not Text:
        Text = "Resource"
    if Text[0].isdigit():
        Text = "_" + Text
    return Text


def BuildHeader(InputPath, DisplayPath, OutputFileName, Namespace, Name):
    Data = InputPath.read_bytes()
    Lines = [
        "#pragma once",
        "",
        f"// {OutputFileName} — 嵌入式二进制资源",
        f"// 自动生成: {DisplayPath}",
        "",
        "#include <cstddef>",
        "#include <cstdint>",
        "",
        f"namespace {Namespace}",
        "{",
        f"inline constexpr std::uint8_t {Name}[] = {{",
    ]

    for Offset in range(0, len(Data), 16):
        Chunk = Data[Offset:Offset + 16]
        Values = ", ".join(f"0x{Value:02X}" for Value in Chunk)
        Lines.append(f"    {Values},")

    Lines.extend([
        "};",
        f"inline constexpr std::size_t {Name}Size = sizeof({Name});",
        f"}} // namespace {Namespace}",
        "",
    ])
    return "\n".join(Lines)


def Main():
    if len(sys.argv) < 3:
        print("usage: GenerateBinaryResource.py <input> <output.hpp> [namespace] [name]")
        return 1

    InputPath = Path(sys.argv[1]).resolve()
    OutputPath = Path(sys.argv[2]).resolve()
    Namespace = sys.argv[3] if len(sys.argv) >= 4 else "RorinnnTools::Resources"
    Name = BuildIdentifier(sys.argv[4] if len(sys.argv) >= 5 else InputPath.stem)
    try:
        DisplayPath = InputPath.relative_to(Path.cwd()).as_posix()
    except ValueError:
        DisplayPath = InputPath.as_posix()

    OutputPath.parent.mkdir(parents=True, exist_ok=True)
    OutputPath.write_text(BuildHeader(InputPath, DisplayPath, OutputPath.name, Namespace, Name),
                          encoding="utf-8",
                          newline="\n")
    return 0


if __name__ == "__main__":
    raise SystemExit(Main())

