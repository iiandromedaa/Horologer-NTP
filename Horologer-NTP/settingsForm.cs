using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Horologer_NTP
{
    public partial class settingsForm : Form
    {
        public static bool SettOpen = false;
        public settingsForm()
        {
            InitializeComponent();
            dateTimePicker1.Format = DateTimePickerFormat.Custom;
            dateTimePicker1.CustomFormat = "hh:mm tt";
            dateTimePicker1.ShowUpDown = true;
        }

        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void dateTimePicker1_ValueChanged(object sender, EventArgs e)
        {
            DateTime tempAlarm = dateTimePicker1.Value;
            DateTime parsedDT = DateTime.ParseExact(dateStr, "H:mm", null, System.Globalization.DateTimeStyles.None);

            if (DateTime.Now > dateTime)
                dateTime = dateTime.AddDays(1);
        }

        private void okButton_Click(object sender, EventArgs e)
        {
            //save settings
            Close();
            Dispose();
            SettOpen = false;
        }

        private void cancelButton_Click(object sender, EventArgs e)
        {
            Close();
            Dispose();
            SettOpen = false;
        }

        private void settingsForm_FormClosed(object sender, FormClosedEventArgs e)
        {
            Close();
            Dispose();
            SettOpen = false;

        }
    }
}
