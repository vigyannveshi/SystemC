'''
Logic: Linux CPP executables doesn't contain ".", hence we shall consider all files, then which ever file doesn't have ".", we shall delete it.
'''

import os

# folders=[]
# def rec_remove(files):
#     print(files)
#     print()
#     if len(files)==0:
#         return
#     # print(files)
#     for file in files:
#         # print(file)
#         # if os.path.isfile(file):
#         #     if not file.__contains__("."):
#         #         # os.remove(file)
#         #         pass
#         if not os.path.isfile(file):
#             # print(file)
#             return rec_remove(os.listdir(file))
# rec_remove(os.listdir())
 

# for file in os.listdir():
#     # print(file)
#     if os.path.isfile(file):
#         if not file.__contains__("."):
#             os.remove(file)
#     if not os.path.isfile(file):
#         print(file)

print("Successfully deleted the executables!")