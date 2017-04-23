/*
** position.c for  in /home/BlackBIrdz/tekadventure/src
** 
** Made by LAABID Zakaria
** Login   <BlackBIrdz@epitech.net>
** 
** Started on  Sat Apr 22 20:40:56 2017 LAABID Zakaria
** Last update Sat Apr 22 20:48:11 2017 LAABID Zakaria
*/

#include "tekadv.h"

void	        set_position_button(t_menu **menu)
{
  sfVector2f	play;
  sfVector2f	play_hover;
  sfVector2f	multi;
  sfVector2f	close;
  sfVector2f    close_hover;

  play = ((sfVector2f) {515.0, 250.0});
  play_hover = ((sfVector2f) {515 - (53 / 2), 250.0 - (57 / 2)});
  multi = ((sfVector2f) {515.0, 305.0});
  close = ((sfVector2f) {515.0, 360.0});
  close_hover = ((sfVector2f) {515 - (53 / 2), 360.0 - (57 / 2)});
  sfSprite_setPosition(menu[2]->sprite, play);
  sfSprite_setPosition(menu[3]->sprite, multi);
  sfSprite_setPosition(menu[4]->sprite, close);
  sfSprite_setPosition(menu[2]->sprite_h, play_hover);
  sfSprite_setPosition(menu[4]->sprite_h, close_hover);
}

void	        set_position_panels(t_menu **menu)
{
  sfVector2f    option;
  sfVector2f	option_hover;
  sfVector2f    shop;
  sfVector2f    shop_hover;
  sfVector2f	news;
  sfVector2f    news_hover;

  option = ((sfVector2f) {455.0, 513.0});
  option_hover = ((sfVector2f) {455.0 - (51 / 2), 513.0 - (53 / 2)});
  shop = ((sfVector2f) {630.0, 513.0});
  shop_hover = ((sfVector2f) {630.0 - (52 / 2), 513.0 - (53 / 2)});
  news = ((sfVector2f) {795.0, 513.0});
  news_hover = ((sfVector2f) {800 - (58 / 2), 513.0 - (53 / 2)});
  sfSprite_setPosition(menu[OPTION]->sprite, option);
  sfSprite_setPosition(menu[SHOP]->sprite, shop);
  sfSprite_setPosition(menu[NEWS]->sprite, news);
  sfSprite_setPosition(menu[OPTION]->sprite_h, option_hover);
  sfSprite_setPosition(menu[SHOP]->sprite_h, shop_hover);
  sfSprite_setPosition(menu[NEWS]->sprite_h, news_hover);
}
