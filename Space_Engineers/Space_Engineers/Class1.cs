using System;
using System.Text;
using System.Collections;
using System.Collections.Generic;
using VRageMath;
using VRage.Game;
using Sandbox.ModAPI.Interfaces;
using Sandbox.ModAPI.Ingame;
using Sandbox.Game.EntityComponents;
using VRage.Game.Components;
using VRage.Collections;
using VRage.Game.ObjectBuilders.Definitions;
using VRage.Game.ModAPI.Ingame;
using SpaceEngineers.Game.ModAPI.Ingame;
public sealed class Program1 : MyGridProgram
{
    // НАЧАЛО СКРИПТА
    //блок кабины и список блоков двигателей
    IMyCockpit Cockpit;
    List<IMyThrust> Thrusters;

    // Просто компенсация g или ховер?
    bool Hover = false;

    //3 переменные для поддержания высоты полета над поверхностью
    double HoverHeight = 0;
    double CurrentHeight = 0;
    double OldHeight = 0;

    //Коэффициент Kv, характеризующий пропорциональную зависимость между разностью требуемой и текущей высот и необходимой вертикальной скоростью
    double Kv = 8;
    //Коэффициент Ka, характеризующий пропорциональную зависимость между разностью требуемой и текущей верт. скоростей и желаемым ускорением
    double Ka = 10;

    //находим нужные блоки
    public Program()
    {
        Cockpit = GridTerminalSystem.GetBlockWithName("Cockpit") as IMyCockpit;
        Thrusters = new List<IMyThrust>();
        GridTerminalSystem.GetBlocksOfType<IMyThrust>(Thrusters);
    }

    //в главной функции запускаем скрипт в рабочем режиме или останавливаем в зависимости от аргумента
    public void Main(string argument, UpdateType uType)
    {
        if (argument == "Compensate")
        {
            Cockpit.DampenersOverride = false;
            Hover = false;
            Runtime.UpdateFrequency = UpdateFrequency.Update1;
            CompensateWeight();
        }
        else if (argument == "Hover")
        {
            Cockpit.TryGetPlanetElevation(MyPlanetElevation.Surface, out HoverHeight);
            CurrentHeight = HoverHeight;
            OldHeight = CurrentHeight;
            Cockpit.DampenersOverride = false;
            Hover = true;
            Runtime.UpdateFrequency = UpdateFrequency.Update1;
            CompensateWeight();
        }
        else if (argument == "Stop")
        {
            foreach (IMyThrust Thruster in Thrusters)
            {
                Thruster.ThrustOverridePercentage = 0f;
            }
            Cockpit.DampenersOverride = true;
            Runtime.UpdateFrequency = UpdateFrequency.None;
        }
        else if (uType == UpdateType.Update1)
        {
            CompensateWeight();
        }
    }

    //это рабочая процедура скрипта. 
    public void CompensateWeight()
    {

        Vector3D GravityVector = Cockpit.GetNaturalGravity();
        float ShipMass = Cockpit.CalculateShipMass().PhysicalMass;

        Vector3D ShipWeight = GravityVector * ShipMass;

        Vector3D HoverThrust = new Vector3D();
        if (Hover)
        {
            HoverThrust = Vector3D.Normalize(GravityVector);

            Cockpit.TryGetPlanetElevation(MyPlanetElevation.Surface, out CurrentHeight);
            double HeightDelta = HoverHeight - CurrentHeight;
            double VerticalSpeed = (CurrentHeight - OldHeight) * 60;
            OldHeight = CurrentHeight;
            HoverThrust = HoverThrust * ShipMass * (HeightDelta * Kv - VerticalSpeed) * Ka;
            Echo(HoverThrust.Length().ToString());
        }

        double ForwardThrust = (ShipWeight + HoverThrust).Dot(Cockpit.WorldMatrix.Forward);
        double LeftThrust = (ShipWeight + HoverThrust).Dot(Cockpit.WorldMatrix.Left);
        double UpThrust = (ShipWeight + HoverThrust).Dot(Cockpit.WorldMatrix.Up);

        double BackwardThrust = -ForwardThrust;
        double RightThrust = -LeftThrust;
        double DownThrust = -UpThrust;



        Matrix CockpitMatrix = new MatrixD();
        Matrix ThrusterMatrix = new MatrixD();

        Cockpit.Orientation.GetMatrix(out CockpitMatrix);

        double UpThrMax = 0;
        double DownThrMax = 0;
        double LeftThrMax = 0;
        double RightThrMax = 0;
        double ForwardThrMax = 0;
        double BackwardThrMax = 0;

        foreach (IMyThrust Thruster in Thrusters)
        {
            Thruster.Orientation.GetMatrix(out ThrusterMatrix);
            //Y
            if (ThrusterMatrix.Forward == CockpitMatrix.Up)
            {
                UpThrMax += Thruster.MaxEffectiveThrust;
            }
            else if (ThrusterMatrix.Forward == CockpitMatrix.Down)
            {
                DownThrMax += Thruster.MaxEffectiveThrust;
            }
            //X
            else if (ThrusterMatrix.Forward == CockpitMatrix.Left)
            {
                LeftThrMax += Thruster.MaxEffectiveThrust;
            }
            else if (ThrusterMatrix.Forward == CockpitMatrix.Right)
            {
                RightThrMax += Thruster.MaxEffectiveThrust;
            }
            //Z
            else if (ThrusterMatrix.Forward == CockpitMatrix.Forward)
            {
                ForwardThrMax += Thruster.MaxEffectiveThrust;
            }
            else if (ThrusterMatrix.Forward == CockpitMatrix.Backward)
            {
                BackwardThrMax += Thruster.MaxEffectiveThrust;
            }
        }

        foreach (IMyThrust Thruster in Thrusters)
        {
            Thruster.Orientation.GetMatrix(out ThrusterMatrix);
            //Y
            if (ThrusterMatrix.Forward == CockpitMatrix.Up)
            {
                Thruster.ThrustOverridePercentage = (float)(UpThrust / UpThrMax);
            }
            else if (ThrusterMatrix.Forward == CockpitMatrix.Down)
            {
                Thruster.ThrustOverridePercentage = (float)(DownThrust / DownThrMax);
            }
            //X
            else if (ThrusterMatrix.Forward == CockpitMatrix.Left)
            {
                Thruster.ThrustOverridePercentage = (float)(LeftThrust / LeftThrMax);
            }
            else if (ThrusterMatrix.Forward == CockpitMatrix.Right)
            {
                Thruster.ThrustOverridePercentage = (float)(RightThrust / RightThrMax);
            }
            //Z
            else if (ThrusterMatrix.Forward == CockpitMatrix.Forward)
            {
                Thruster.ThrustOverridePercentage = (float)(ForwardThrust / ForwardThrMax);
            }
            else if (ThrusterMatrix.Forward == CockpitMatrix.Backward)
            {
                Thruster.ThrustOverridePercentage = (float)(BackwardThrust / BackwardThrMax);
            }
        }
    }

    // КОНЕЦ СКРИПТА
}