using static Horologer_NTP.AboutBox1;
namespace Horologer_NTP
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void time_Click(object sender, EventArgs e)
        {

        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void aboutToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (AboutBox1.aboutOpen == false) {
                new AboutBox1().Show();
                aboutOpen = true;
            }
        }
    }
}