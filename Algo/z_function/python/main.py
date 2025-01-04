from z_function import z_function

if __name__ == "__main__":
    s = "aabcaabxaaaz"
    z = z_function(s)

    z.cal_z()
    z.show_res()