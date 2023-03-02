using static Horologer_NTP.Program;
using static Horologer_NTP.Settings1;

namespace Horologer_NTP
{
    public partial class settingsForm : Form
    {
        public static bool SettOpen = false;
        private string curNTP;

        public settingsForm()
        {
            InitializeComponent();
            dateTimePicker1.Format = DateTimePickerFormat.Custom;
            dateTimePicker1.CustomFormat = "hh:mm tt";
            dateTimePicker1.ShowUpDown = true;

            //load settings
        }

        private void loadVals()
        {
            DateTime dtPickerDef = Properties.Settings1.Default.Alarm0;
            String ntpPickerDef = Properties.Settings1.Default.NTPserver;
            int displayPickerDef = Properties.Settings1.Default.DisplayType;
        }

        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void dateTimePicker1_ValueChanged(object sender, EventArgs e)
        {
            DateTime timePicked = dateTimePicker1.Value;
            DateTime parsedDT = DateTime.ParseExact(timePicked.ToString(), "H:mm", null, System.Globalization.DateTimeStyles.None);

            if (GetNetworkTime2(curNTP) > parsedDT)
                parsedDT.AddDays(1);
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
