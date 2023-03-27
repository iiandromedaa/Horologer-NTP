using System.Diagnostics;
using static Horologer_NTP.Program;
using static Horologer_NTP.Settings1;

namespace Horologer_NTP
{
    public partial class settingsForm : Form
    {
        public static bool SettOpen = false;
        private string curNTP;
        DateTime parsedDT;
        public settingsForm()
        {
            InitializeComponent();
            dateTimePicker1.Format = DateTimePickerFormat.Custom;
            dateTimePicker1.CustomFormat = "hh:mm tt";
            dateTimePicker1.ShowUpDown = true;
            //load settings
            dateTimePicker1.Value = Properties.Settings1.Default.Alarm0;
            textBox1.Text = Properties.Settings1.Default.NTPserver;
            if (Properties.Settings1.Default.DisplayType == 0)
            {
                comboBox1.Text = "12 Hour";
            }
            else if (Properties.Settings1.Default.DisplayType == 1) 
            {
                comboBox1.Text = "24 Hour";
            }
        }

        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void dateTimePicker1_ValueChanged(object sender, EventArgs e)
        {
            DateTime timePicked = dateTimePicker1.Value;
            parsedDT = DateTime.ParseExact(timePicked.ToString(), "hh:mm tt", null, System.Globalization.DateTimeStyles.None);
            if (GetNetworkTime2(curNTP) > parsedDT)
                parsedDT.AddDays(1);
            //Debug.WriteLine(parsedDT);
            Debug.WriteLine(timePicked);
        }

        private void okButton_Click(object sender, EventArgs e)
        {
            Debug.WriteLine(parsedDT.ToString());
            SaveVals();
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
            SaveVals();
            Close();
            Dispose();
            SettOpen = false;

        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            curNTP = textBox1.Text;
        }
        private void LoadVals()
        {
            DateTime dtPickerDef = Properties.Settings1.Default.Alarm0;
            String ntpPickerDef = Properties.Settings1.Default.NTPserver;
            int displayPickerDef = Properties.Settings1.Default.DisplayType;
        }

        private void SaveVals()
        {
            Properties.Settings1.Default.Alarm0 = parsedDT;
            Properties.Settings1.Default.NTPserver = curNTP;
        }
    }
}
