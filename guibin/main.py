import time
from tkinter import filedialog
from tkinter import messagebox

import ttkbootstrap as ttk
from ttkbootstrap.constants import *

import tkinter as tk

from ctypes import *


class RetTwoDim(Structure):
    _fields_ = [
        ('dataList', (c_char_p * 1000) * 1000),
        ('dataNumOne', c_int * 1000),
        ('dataNumTwo', c_int)
    ]


class RetOneDim(Structure):
    _fields_ = [
        ('dataList', c_char_p * 1000),
        ('dataNum', c_int)
    ]


root = ttk.Window()
root.title("WordList")
sw = root.winfo_screenwidth()
sh = root.winfo_screenheight()
ww = 800
wh = 600
x = (sw - ww) / 2
y = (sh - wh) / 2
root.geometry("%dx%d+%d+%d" % (ww, wh, x, y))

ttk.Label(root, text="WordList GUI", anchor="center", style="inverse-primary",
          font=("Times New Roman", 20, "bold")).place(relx=0, rely=0, relwidth=1, relheight=0.1)

dataFrame = ttk.LabelFrame(root, text="Import Data", labelanchor="n")
dataFrame.place(relx=0, rely=0.12, relwidth=1, relheight=0.3)

dataBFrame = ttk.Frame(dataFrame)
dataBFrame.place(relx=0, rely=0, relwidth=0.3, relheight=1)

way2choose = ""

dataHFrame = ttk.Frame(dataFrame, name="input")

scrollbar = ttk.Scrollbar(dataHFrame, style="primary-round")
dataText = ttk.Text(dataHFrame, wrap="word", yscrollcommand=scrollbar.set)
scrollbar.config(command=dataText.yview)

scrollbar.pack(fill=Y, side='right')
dataText.place(relx=0.1, rely=0.1, relwidth=0.8, relheight=0.8)

dataFFrame = ttk.Frame(dataFrame, name="file")


def askFileName(label):
    global filename

    filename = filedialog.askopenfilename()
    if filename != "":
        label.config(text=filename)


filename = "No file has been selected."
filenameLabel = ttk.Label(dataFFrame, text=filename, anchor="center")
tk.Button(dataFFrame, text="Choose File", command=lambda: askFileName(filenameLabel),
          font=("Times New Roman", 12)).place(relx=0.2, rely=0.2,
                                              relwidth=0.6,
                                              relheight=0.3)
filenameLabel.place(relx=0.15, rely=0.55, relwidth=0.7, relheight=0.3)


def frameShow(frame1, frame2):
    global way2choose

    frame1.place_forget()
    frame2.place(relx=0.3, rely=0, relwidth=0.7, relheight=1)

    way2choose = frame2.winfo_name()


ttk.Button(dataBFrame, text="Input Directly", command=lambda: frameShow(dataFFrame, dataHFrame),
           style="outline-info").place(relx=0.25,
                                       rely=0.12,
                                       relwidth=0.6,
                                       relheight=0.26)
ttk.Button(dataBFrame, text="File Import", command=lambda: frameShow(dataHFrame, dataFFrame),
           style="outline-info").place(relx=0.25,
                                       rely=0.62,
                                       relwidth=0.6,
                                       relheight=0.26)

frameShow(dataFFrame, dataHFrame)

paraFrame = ttk.LabelFrame(root, text="Choose Parameter", labelanchor="n")
paraFrame.place(relx=0, rely=0.45, relwidth=1, relheight=0.25)

eParaFrame = ttk.LabelFrame(paraFrame, text="essential parameter", style="secondary", labelanchor="n")
eParaFrame.place(relx=0.01, rely=0, relwidth=0.485, relheight=0.95)

aParaFrame = ttk.LabelFrame(paraFrame, text="additional parameter", style="secondary", labelanchor="n")
aParaFrame.place(relx=0.505, rely=0, relwidth=0.485, relheight=0.95)

eParaChoose = ttk.StringVar()

ttk.Radiobutton(eParaFrame, variable=eParaChoose, value="-n",
                text="-n Count the words chain in a word text.").place(relx=0.02, rely=0.1,
                                                                       relwidth=0.98,
                                                                       relheight=0.25)
ttk.Radiobutton(eParaFrame, variable=eParaChoose, value="-w",
                text="-w Count the words chain with the highest number of words.").place(relx=0.02, rely=0.35,
                                                                                         relwidth=0.98,
                                                                                         relheight=0.25)
ttk.Radiobutton(eParaFrame, variable=eParaChoose, value="-c",
                text="-c Count the words chain with the most letters.").place(relx=0.02, rely=0.6, relwidth=0.98,
                                                                              relheight=0.25)

aParaChoose = [ttk.IntVar(value=0) for _ in range(4)]
aParaContent = [ttk.StringVar() for _ in range(3)]


def additionalCBUpdata(entry, isOn):
    if isOn:
        entry.config(bootstyle="primary")
        entry.config(state="normal")
    else:
        entry.delete(0, ttk.END)
        entry.validate()
        entry.config(bootstyle="default")
        entry.config(state="disabled")


def validate_alpha(s) -> bool:
    if len(s) > 1:
        return False
    elif s.isalpha():
        return True
    elif s == "":
        return True
    else:
        return False


alpha_func = root.register(validate_alpha)

e1 = ttk.Entry(aParaFrame, textvariable=aParaContent[0], state="disabled", validate="focus",
               validatecommand=(alpha_func, '%P'))
e1.place(relx=0.4, rely=0.1,
         relwidth=0.1,
         relheight=0.22)
e2 = ttk.Entry(aParaFrame, textvariable=aParaContent[1], state="disabled", validate="focus",
               validatecommand=(alpha_func, '%P'))
e2.place(relx=0.4, rely=0.35,
         relwidth=0.1,
         relheight=0.22)
e3 = ttk.Entry(aParaFrame, textvariable=aParaContent[2], state="disabled", validate="focus",
               validatecommand=(alpha_func, '%P'))
e3.place(relx=0.4, rely=0.6,
         relwidth=0.1,
         relheight=0.22)

ttk.Checkbutton(aParaFrame, text="-h The first letter.", variable=aParaChoose[0], onvalue=1, offvalue=0,
                command=lambda: additionalCBUpdata(e1, aParaChoose[0].get())).place(relx=0.01, rely=0.1,
                                                                                    relwidth=0.38,
                                                                                    relheight=0.25)
ttk.Checkbutton(aParaFrame, text="-t The last letter.", variable=aParaChoose[1], onvalue=1, offvalue=0,
                command=lambda: additionalCBUpdata(e2, aParaChoose[1].get())).place(relx=0.01, rely=0.35,
                                                                                    relwidth=0.38,
                                                                                    relheight=0.25)
ttk.Checkbutton(aParaFrame, text="-j Initials not allowed.", variable=aParaChoose[2], onvalue=1, offvalue=0,
                command=lambda: additionalCBUpdata(e3, aParaChoose[2].get())).place(relx=0.01, rely=0.6,
                                                                                    relwidth=0.38,
                                                                                    relheight=0.25)
ttk.Checkbutton(aParaFrame, text="-r Implied word rings.", variable=aParaChoose[3], onvalue=1, offvalue=0).place(
    relx=0.55, rely=0.1,
    relwidth=0.4,
    relheight=0.25)


def checkForAllPara() -> int:
    global aParaChoose, aParaContent, way2choose, filename, eParaChoose

    if eParaChoose.get() == "":
        return 4

    if way2choose == "file" and filename == "No file has been selected.":
        return 3

    for i in range(3):
        if aParaChoose[i].get() != 0:
            s = aParaContent[i].get()
            if len(s) > 1:
                return 1
            elif not s.isalpha():
                return 1

    if aParaChoose[0].get() != 0 and aParaChoose[2].get() != 0 and aParaContent[0].get() == aParaContent[2].get():
        return 2

    return 0


def deleteNewWindow(win):
    win.deiconify()


def startCalculate(win):
    check = checkForAllPara()
    if check == 1:
        messagebox.showerror(title="error", message="You should type in one letter, not a word or a digit!")
        return
    elif check == 2:
        messagebox.showerror(title="error", message="-h and -j parameter conflicts!")
        return
    elif check == 3:
        messagebox.showerror(title="error", message="You have not chosen a file to import data!")
        return
    elif check == 4:
        messagebox.showerror(title="error", message="You have not chosen an essential parameter!")
        return

    win.withdraw()

    top = ttk.Toplevel()
    top.title("Result")
    top_sw = top.winfo_screenwidth()
    top_sh = top.winfo_screenheight()
    top_ww = 600
    top_wh = 400
    top_x = (top_sw - top_ww) / 2
    top_y = (top_sh - top_wh) / 2
    top.geometry("%dx%d+%d+%d" % (top_ww, top_wh, top_x, top_y))

    top.protocol("WM_DELETE_WINDOW", lambda: deleteNewWindow(win))

    ttk.Label(top, text="Result", anchor="center", style="inverse-primary", font=("Times New Roman", 20, "bold")).place(
        relx=0, rely=0, relwidth=1,
        relheight=0.1)

    global way2choose, dataText, filename, eParaChoose, aParaChoose, aParaContent

    data = []
    # 数据处理
    if way2choose == "input":
        data = dataText.get("1.0", ttk.END).split()
    else:
        with open(filename, 'r') as f:
            data = f.read().split()

    # print(data,eParaChoose.get(),aParaChoose[0].get())
    data_ctypes = []
    for i in data:
        data_ctypes.append(i.encode('utf-8'))
    data_words = (c_char_p * len(data))(*data_ctypes)

    paras = []
    for i in range(3):
        if aParaChoose[i].get() == 0:
            paras.append(b'\0')
        else:
            paras.append(bytes(aParaContent[i].get())[0])
    if aParaChoose[3] == 0:
        paras.append(False)
    else:
        paras.append(True)

    out = []
    start = end = 0
    if eParaChoose.get() == "-n":
        libc = windll.LoadLibrary("./libapi.dll")
        func = libc.gen_chains_all_cpy
        func.restype = POINTER(RetTwoDim)

        start = time.time()
        ret = func(pointer(data_words), c_int(len(data)))
        end = time.time()

        for i in range(ret.contents.dataNumTwo):
            out_s = ""
            for j in range(ret.contents.dataNumOne[i]):
                out_s += ret.contents.dataList[i][j]
            out.append(out_s)
        pass

    elif eParaChoose.get() == "-w":
        libc = windll.LoadLibrary("./libapi.dll")
        func = libc.gen_chain_word_cpy
        func.restype = POINTER(RetOneDim)

        start = time.time()
        ret = func(pointer(data_words),
                   c_int(len(data)),
                   c_char(paras[0]),
                   c_char(paras[1]),
                   c_char(paras[2]),
                   c_bool(paras[3]))

        end = time.time()

        for i in range(ret.contents.dataNum):
            out.append(ret.contents.dataList[i])

    elif eParaChoose.get() == "-c":
        libc = windll.LoadLibrary("./libapi.dll")
        func = libc.gen_chain_char_cpy
        func.restype = POINTER(RetOneDim)

        start = time.time()
        ret = func(pointer(data_words),
                   c_int(len(data)),
                   c_char(paras[0]),
                   c_char(paras[1]),
                   c_char(paras[2]),
                   c_bool(paras[3]))
        end = time.time()

        for i in range(ret.contents.dataNum):
            out.append(ret.contents.dataList[i])

    runtime = end - start
    print(start,end)

    ttk.Label(top, text="This calculation took %.2f s" % runtime, anchor="center",
              font=("Times New Roman", 15, "bold")).place(
        relx=0, rely=0.1,
        relwidth=1,
        relheight=0.1)
    frame = ttk.Frame(top)
    frame.place(relx=0.2, rely=0.2, relwidth=0.6, relheight=0.55)

    scrollbarNew = ttk.Scrollbar(frame, style="primary-round")
    scrollbarNew.pack(side="right", fill=Y)
    listbox = tk.Listbox(frame, yscrollcommand=scrollbarNew.set)
    scrollbarNew.config(command=listbox.yview())

    for i in out:
        listbox.insert(tk.END, i)

    listbox.place(relx=0, rely=0, relheight=1, relwidth=0.96)

    # ttk.Label(top, text="\n".join(out), anchor="nw").place()

    def saveResult(result):
        name = filedialog.askopenfilename()

        if name != "":
            with open(name, 'w') as f:
                f.write("\n".join(result))
                f.close()
                messagebox.showinfo(title="Success", message="Save successfully!")
        else:
            messagebox.showerror(title="error", message="You have not chosen a file!")

    tk.Button(top, text="Save Result", command=lambda: saveResult(out), font=("Times New Roman", 15)).place(relx=0.3,
                                                                                                            rely=0.8,
                                                                                                            relwidth=0.4,
                                                                                                            relheight=0.12)


tk.Button(root, text="Start Calculate", command=lambda: startCalculate(root), font=("Times New Roman", 18)).place(
    relx=0.2, rely=0.75, relwidth=0.6,
    relheight=0.15)

root.mainloop()
