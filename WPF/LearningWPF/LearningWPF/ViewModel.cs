using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Input;

namespace LearningWPF
{
    public class ViewModel
    {
        public ICommand myCommand { get; set; }

        public ViewModel()
        {
            myCommand = new CommandExample(Execute,CanExecute);
        }
        public void Execute(object paramter)
        {
            MessageBox.Show("No code behind");
        }

        public bool CanExecute(object parameter)
        {
            return true;
        }
    }
}
