using static Horologer_NTP.AboutBox1;
namespace Horologer_NTP
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            Stopwatcher();
        }

        private void time_Click(object sender, EventArgs e)
        {
            UpdateTime();
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void aboutToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (!aboutOpen) {
                new AboutBox1().Show();
                aboutOpen = true;
            }
        }
        public void UpdateTime()
        {
            time.Text = DateTime.Now.ToString("hh:mm:ss tt");
        }

        public async Task Stopwatcher()
        {
            while (true)
            {
                var delayTask = Task.Delay(100);
                UpdateTime();
                await delayTask; // wait until at least 10s elapsed since delayTask created
            }
        }
    }
}