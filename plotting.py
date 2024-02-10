import matplotlib.pyplot as plt
import csv

# Initialize lists for main plot (time and signal)
x_main = []
y_main = []


#next subplot 3pt moving average
x_3pt = [];
y_3pt = [];

#next subplot 5pt moving average
x_5pt = [];
y_5pt = [];

#next subplot 7pt moving average
x_7pt = [];
y_7pt = [];

x_3pt_binomial = []
y_3pt_binomial = []

x_5pt_binomial = []
y_5pt_binomial = []

x_7pt_binomial = []
y_7pt_binomial = []


# Read data from the CSV file
with open("output_data.csv", "r") as csvfile:
    plots = csv.reader(csvfile, delimiter=',')
    for row in plots:
        x_main.append(float(row[0]))  # Time for main plot
        y_main.append(float(row[3]))  # Signal + noise for subplot (x_sub is the same as x_main)
          # Signal + noise for subplot (x_sub is the same as x_main)
        x_3pt.append(float(row[0])) #time for 3pt mov avg
        x_5pt.append(float(row[0])) #time for 5pt mov avg
        x_7pt.append(float(row[0])) #time for 7pt mov avg

        x_3pt_binomial.append(float(row[0])) #time for 3pt mov avg
        x_5pt_binomial.append(float(row[0])) #time for 5pt mov avg
        x_7pt_binomial.append(float(row[0])) #time for 7pt mov avg
        
        


with open("three_point_mov_avg.csv", "r") as csvfile:
    plots = csv.reader(csvfile, delimiter=',')
    for row in plots:
        y_3pt.append(float(row[0])) #append three point moving average

with open("five_point_mov_avg.csv", "r") as csvfile:
    plots = csv.reader(csvfile,delimiter=',') 
    for row in plots:
        y_5pt.append(float(row[0])) ##append 5pt moving average

with open("seven_point_mov_avg.csv", "r") as csvfile:
    plots = csv.reader(csvfile,delimiter=',') 
    for row in plots:
        y_7pt.append(float(row[0])) ##append pt moving average

with open("three_point_binomial.csv", "r") as csvfile:
    plots = csv.reader(csvfile,delimiter=',') 
    for row in plots:
        y_3pt_binomial.append(float(row[0])) ##append pt moving average

with open("five_point_binomial.csv", "r") as csvfile:
    plots = csv.reader(csvfile,delimiter=',') 
    for row in plots:
        y_5pt_binomial.append(float(row[0])) ##append pt moving average

with open("seven_point_binomial.csv", "r") as csvfile:
    plots = csv.reader(csvfile,delimiter=',') 
    for row in plots:
        y_7pt_binomial.append(float(row[0])) ##append pt moving average




#remove 0th and last element from 3pt time
x_3pt = x_3pt[1:-1]
x_5pt = x_5pt[2:-2]
x_7pt = x_7pt[3:-3]

x_3pt_binomial = x_3pt_binomial[1:-1]
x_5pt_binomial = x_5pt_binomial[2:-2]
x_7pt_binomial = x_7pt_binomial[3:-3]


# Create a figure with subplots
fig, axs = plt.subplots(4, 1, figsize=(8, 20))
ax_main, ax_3pt, ax_5pt, ax_7pt = axs  # 5rows, 1 column
# Plot main data
ax_main.plot(x_main, y_main, 'r-', label='Signal')
ax_main.set_xlabel('Time (t)')
ax_main.set_ylabel('Signal (Hz)')
ax_main.set_title('Signal vs. Time')
ax_main.legend()
ax_main.grid(True)


# Plot 3pt moving average data
ax_3pt.plot(x_3pt, y_3pt, 'g-', label='3pt Moving Avg')
ax_3pt.set_xlabel('Time (t)')
ax_3pt.set_ylabel('3pt Moving Avg (Hz)')
ax_3pt.set_title('3pt Moving Average vs. Time')
ax_3pt.legend()
ax_3pt.grid(True)

ax_5pt.plot(x_5pt, y_5pt, 'k-', label='5pt Moving Avg')
ax_5pt.set_xlabel('Time (t)')
ax_5pt.set_ylabel('5pt Moving Avg (Hz)')
ax_5pt.set_title('5pt Moving Average vs. Time')
ax_5pt.legend()
ax_5pt.grid(True)

ax_7pt.plot(x_7pt, y_7pt, 'b-', label='7pt Moving Avg')
ax_7pt.set_xlabel('Time (t)')
ax_7pt.set_ylabel('7pt Moving Avg (Hz)')
ax_7pt.set_title('7pt Moving Average vs. Time')
ax_7pt.legend()
ax_7pt.grid(True)


#plt.tight_layout()

# Show the plot
#plt.show()


fig, axs_binomial = plt.subplots(4, 1, figsize=(8, 20))  


ax_main_binomial, ax_3pt_binomial, ax_5pt_binomial, ax_7pt_binomial = axs_binomial

# Plot main data on the corrected ax_main_binomial axis
ax_main_binomial.plot(x_main, y_main, 'r-', label='Signal')
ax_main_binomial.set_xlabel('Time (t)')
ax_main_binomial.set_ylabel('Signal (Hz)')
ax_main_binomial.set_title('Signal vs. Time')
ax_main_binomial.legend()
ax_main_binomial.grid(True)

# Plot 3pt binomial filter data
ax_3pt_binomial.plot(x_3pt_binomial, y_3pt_binomial, 'g-', label='3pt Binomial filter')
ax_3pt_binomial.set_xlabel('Time (t)')
ax_3pt_binomial.set_ylabel('3pt Binomial filter (Hz)')
ax_3pt_binomial.set_title('3pt Binomial filter vs. Time')
ax_3pt_binomial.legend()
ax_3pt_binomial.grid(True)

# Plot 5pt binomial filter data
ax_5pt_binomial.plot(x_5pt_binomial, y_5pt_binomial, 'k-', label='5pt Binomial filter')
ax_5pt_binomial.set_xlabel('Time (t)')
ax_5pt_binomial.set_ylabel('5pt Binomial filter (Hz)')
ax_5pt_binomial.set_title('5pt Binomial filter vs. Time')
ax_5pt_binomial.legend()
ax_5pt_binomial.grid(True)

# Plot 7pt binomial filter data
ax_7pt_binomial.plot(x_7pt_binomial, y_7pt_binomial, 'b-', label='7pt Binomial filter')
ax_7pt_binomial.set_xlabel('Time (t)')
ax_7pt_binomial.set_ylabel('7pt Binomial filter (Hz)')
ax_7pt_binomial.set_title('7pt Binomial filter vs. Time')
ax_7pt_binomial.legend()
ax_7pt_binomial.grid(True)

plt.tight_layout()  
plt.show()
