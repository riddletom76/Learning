using OdeToFood.Core;
using System.Collections.Generic;
using System.Text;

namespace OdeToFood.Data
{
    public interface IRestaurantData
    {
        IEnumerable<Restaurants> GetRestaurantsByName(string restaurantName);
        Restaurants GetRestaurantById(int restaurantId);
        Restaurants UpdateRestaurant(Restaurants updatedRestaurant);
        Restaurants AddNewRestaurant(Restaurants newRestaurant);
        Restaurants DeleteRestaurant(int restaurantId);
        int Commit();
    }
}
